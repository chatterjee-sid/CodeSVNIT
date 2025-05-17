#client3.py
import socket
from datetime import datetime

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5006

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (SERVER_IP, SERVER_PORT)

fullmessage = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Omnis odio cumque exercitationem qui consequatur tempora sed fuga accusantium, suscipit, vero architecto nihil asperiores corrupti saepe. Culpa eos molestiae doloremque quasi vel pariatur blanditiis magnam veritatis repudiandae beatae nam quae incidunt sint porro, nesciunt, et quas ullam, corrupti adipisci repellat quo."

message = fullmessage[:32]
i = 0
while message:
    sock.sendto(message.encode(), server_address)
    print(f"Sent: {message}")

    ack, _ = sock.recvfrom(1024) 
    print(f"Received: {ack.decode()} at {datetime.now()}")
    i += 32
    message = fullmessage[i:i+32]

sock.close()
