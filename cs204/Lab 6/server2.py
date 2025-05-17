#server2.py
import socket

RECEIVER_IP = "127.0.0.1"
RECEIVER_PORT = 5005

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((RECEIVER_IP, RECEIVER_PORT))

print(f"Receiver is listening on {RECEIVER_IP}:{RECEIVER_PORT}")

while True:
    data, addr = sock.recvfrom(1024)
    message = data.decode()
    seq_num, payload = message.split("|", 1)

    print(f"Received: \"{payload}\" with seq_no {seq_num}")
    ack_msg = f"ACK{seq_num}".encode()
    sock.sendto(ack_msg, addr)
    print(f"Sent {ack_msg.decode()}")