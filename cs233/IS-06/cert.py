from cryptography import x509
from cryptography.x509.oid import NameOID
from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import rsa
from datetime import datetime, timedelta

private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048
)

subject = issuer = x509.Name([
    x509.NameAttribute(NameOID.COUNTRY_NAME, "IN"),
    x509.NameAttribute(NameOID.STATE_OR_PROVINCE_NAME, "Gujarat"),
    x509.NameAttribute(NameOID.LOCALITY_NAME, "Surat"),
    x509.NameAttribute(NameOID.ORGANIZATION_NAME, "SVNIT"),
    x509.NameAttribute(NameOID.COMMON_NAME, "localhost"),
])

cert = (
    x509.CertificateBuilder()
    .subject_name(subject)
    .issuer_name(issuer)
    .public_key(private_key.public_key())
    .serial_number(x509.random_serial_number())
    .not_valid_before(datetime.now())
    .not_valid_after(datetime.now() + timedelta(days=30))
    .add_extension(x509.BasicConstraints(ca=True, path_length=None), critical=True)
    .sign(private_key, hashes.SHA256())
)

with open("selfsigned.key", "wb") as f:
    f.write(private_key.private_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PrivateFormat.TraditionalOpenSSL,
        encryption_algorithm=serialization.NoEncryption()
    ))

with open("selfsigned.crt", "wb") as f:
    f.write(cert.public_bytes(serialization.Encoding.PEM))

print("Self-signed SSL certificate and private key generated successfully.")
print("Files: selfsigned.crt (certificate) and selfsigned.key (private key)")
