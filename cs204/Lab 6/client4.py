#client4.py
import socket
import time

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5007
INITIAL_RATE = 1
RATE_INCREASE = 0.2
RATE_DECREASE = 0.5

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (SERVER_IP, SERVER_PORT)

rate = INITIAL_RATE

fullmessage = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Omnis odio cumque exercitationem qui consequatur tempora sed fuga accusantium, suscipit, vero architecto nihil asperiores corrupti saepe. Culpa eos molestiae doloremque quasi vel pariatur blanditiis magnam veritatis repudiandae beatae nam quae incidunt sint porro, nesciunt, et quas ullam, corrupti adipisci repellat quo."

message = fullmessage[:32]
i = 0

while message:
    sock.sendto(message.encode(), server_address)
    print(f"Sent: {message}")

    try:
        sock.settimeout(2)
        ack, _ = sock.recvfrom(1024)
        print(f"Received: {ack.decode()} at {rate}")
        rate += RATE_INCREASE
        i += 32
        message = fullmessage[i:i+32]
    except socket.timeout:
        print(f"Packet loss detected! Reducing rate from {rate}.")
        rate *= RATE_DECREASE

    time.sleep(1 / rate)

sock.close()
