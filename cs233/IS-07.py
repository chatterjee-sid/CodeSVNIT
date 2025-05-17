import hashlib
import base64
import os
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import hashes, serialization

def generate_sha256_hash(content):
    """Generate SHA-256 hash of the given content."""
    return hashlib.sha256(content.strip().encode()).hexdigest()

def encrypt_rsa(public_key, data):
    """Encrypt data using RSA encryption."""
    encrypted = public_key.encrypt(
        data.encode(),
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return base64.b64encode(encrypted).decode()

def decrypt_rsa(private_key, encrypted_data):
    """Decrypt RSA-encrypted data."""
    try:
        encrypted_data = base64.b64decode(encrypted_data.strip())
        decrypted = private_key.decrypt(
            encrypted_data,
            padding.OAEP(
                mgf=padding.MGF1(algorithm=hashes.SHA256()),
                algorithm=hashes.SHA256(),
                label=None
            )
        )
        return decrypted.decode()
    except Exception as e:
        print(f"Decryption failed: {e}")
        return None

def embed_watermark(file_path, public_key):
    """Embed a cryptographic watermark in a text file if one doesn't already exist."""
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read().strip()
    
    if "<!-- WATERMARK:" in content:
        print("Watermark already exists. Skipping embedding.")
        return
    
    hash_value = generate_sha256_hash(content)
    encrypted_watermark = encrypt_rsa(public_key, hash_value)
    
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(content + f"\n<!-- WATERMARK:{encrypted_watermark} -->")
    print("Watermark embedded successfully.")

def verify_watermark(file_path, private_key):
    """Verify the cryptographic watermark in a text file."""
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read().strip()
    
    if "<!-- WATERMARK:" not in content:
        print("No watermark found.")
        return
    
    parts = content.rsplit("<!-- WATERMARK:", 1)
    clean_content = parts[0].strip()
    encrypted_watermark = parts[1].strip(" -->") if len(parts) > 1 else ""
    
    expected_hash = generate_sha256_hash(clean_content)
    decrypted_hash = decrypt_rsa(private_key, encrypted_watermark)
    
    if decrypted_hash is None:
        print("Watermark verification failed: Decryption error.")
        return
    
    if expected_hash == decrypted_hash:
        print("Watermark verified: File is authentic.")
    else:
        print("Watermark verification failed: File has been modified.")

def save_keys(private_key, public_key):
    """Save RSA keys to files."""
    with open("private_key.pem", "wb") as private_file:
        private_file.write(private_key.private_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PrivateFormat.PKCS8,
            encryption_algorithm=serialization.NoEncryption()
        ))
    
    with open("public_key.pem", "wb") as public_file:
        public_file.write(public_key.public_bytes(
            encoding=serialization.Encoding.PEM,
            format=serialization.PublicFormat.SubjectPublicKeyInfo
        ))

def load_keys():
    """Load RSA keys from files, or generate new ones if not found."""
    if os.path.exists("private_key.pem") and os.path.exists("public_key.pem"):
        with open("private_key.pem", "rb") as private_file:
            private_key = serialization.load_pem_private_key(
                private_file.read(),
                password=None
            )
        with open("public_key.pem", "rb") as public_file:
            public_key = serialization.load_pem_public_key(
                public_file.read()
            )
    else:
        private_key = rsa.generate_private_key(
            public_exponent=65537,
            key_size=2048
        )
        public_key = private_key.public_key()
        save_keys(private_key, public_key)
    return private_key, public_key

# Load or generate keys
private_key, public_key = load_keys()
file_path = "sample.txt"  # Change to your text file

# Embed watermark
embed_watermark(file_path, public_key)

# Verify watermark
verify_watermark(file_path, private_key)