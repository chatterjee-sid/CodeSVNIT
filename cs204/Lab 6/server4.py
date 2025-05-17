#server4.py
import socket
import random
from datetime import datetime

RECEIVER_IP = "127.0.0.1"
RECEIVER_PORT = 5007

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((RECEIVER_IP, RECEIVER_PORT))

print(f"Receiver is listening on {RECEIVER_IP}:{RECEIVER_PORT}")

while True:
    start = datetime.now()
    data, addr = sock.recvfrom(1024)
    message = data.decode()
    end = datetime.now()
    diff = end-start
    mdiff = diff.seconds + diff.microseconds*0.000001

    if 0.5/mdiff < random.random():  #impossible at timediff less than 500 ms (or rate >= 2)
        ack = "ACK"
        sock.sendto(ack.encode(), addr)
        print(f"Received: {message}, Sent: {ack}")
    else:
        print(f"Packet dropped! Simulating congestion.")