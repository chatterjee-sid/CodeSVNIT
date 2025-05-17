#server3.py
import socket
import time
from datetime import datetime

RECEIVER_IP = "127.0.0.1"
RECEIVER_PORT = 5006

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((RECEIVER_IP, RECEIVER_PORT))

print(f"Receiver is listening on {RECEIVER_IP}:{RECEIVER_PORT}")

while True:
    data, addr = sock.recvfrom(1024)
    print(f"Received: {data.decode()} at {datetime.now()}")

    time.sleep(1)

    sock.sendto(b"OK", addr)
    print("Sent: OK")
