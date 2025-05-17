import random

def diffie_hellman_key_exchange(p, g, a, b):
    print("Numbers publicly agreed upon:")
    print(f"p: {p}")
    print(f"g: {g}")
    # Alice computes A = g^a mod p
    A = pow(g, a, p)
    print(f"Alice's public key: {A}")
    # Bob computes B = g^b mod p
    B = pow(g, b, p)
    print(f"Bob's public key: {B}")
    # Alice computes k = B^a mod p
    k_a = pow(B, a, p)
    # Bob computes k = A^b mod p
    k_b = pow(A, b, p)
    return k_a == k_b, k_a

print("Let's say the computer is Alice and the user is Bob")
p = int(input("Enter a large prime number p: "))
g = int(input("Enter a base g: "))
a = random.randint(1, 10**6)
b = int(input("Enter a secret number b: "))
l,m = diffie_hellman_key_exchange(p, g, a, b)
if l:
    print(f"Shared secret key: {m}")
else:
    print("Key exchange failed")