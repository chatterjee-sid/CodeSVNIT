from sympy import mod_inverse, isprime
from random import getrandbits, randrange
from math import gcd

def generate_large_prime(bit_length):
    while True:
        p = getrandbits(bit_length)
        if isprime(p):
            return p
        
def phi_n(p, q):
    return (p - 1) * (q - 1)
        
def public_exponent(phi_n):
    while True:
        e = randrange(2, phi_n)
        if gcd(e, phi_n) == 1:
            return e

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def private_key(e, phi_n):
    return mod_inverse(e, phi_n)

def encrypt(message, e, n):
    return pow(message, e, n)

def decrypt(ciphertext, d, n):
    return pow(ciphertext, d, n)

message = int(input("Enter a message (integer) to encrypt: "))
bitlength = int(input("Enter the bit length for prime generation (e.g., 512): "))
p = generate_large_prime(bitlength)
q = generate_large_prime(bitlength)
n = p * q
phi = phi_n(p, q)
e = public_exponent(phi)
d = private_key(e, phi)
encrypted_message = encrypt(message, e, n)
print("Encrypted message: ",encrypted_message)
decrypted_message = decrypt(encrypted_message, d, n)
print("Decrypted message: ", decrypted_message)
if message == decrypted_message:
    print("Encryption and decryption successful!")