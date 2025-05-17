#client2.py
import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5005
TIMEOUT = 2

def reliable_send(sock, addr, data):
    seq_num = 0
    while True:
        payload = data[seq_num*32:seq_num*32+32]
        if not payload:
            break
        message = f"{seq_num}|{payload}".encode()
        sock.sendto(message, addr)
        print(f"Sent: \"{message.decode()}\"")

        sock.settimeout(TIMEOUT)
        try:
            ack, _ = sock.recvfrom(1024)
            ack = ack.decode()
            if ack == f"ACK{seq_num}":
                print(f"Received ACK{seq_num}")
                seq_num += 1
        except socket.timeout:
            print("Timeout! Retransmitting...")

if __name__ == "__main__":
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = (SERVER_IP, SERVER_PORT)

    fullmessage = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Omnis odio cumque exercitationem qui consequatur tempora sed fuga accusantium, suscipit, vero architecto nihil asperiores corrupti saepe. Culpa eos molestiae doloremque quasi vel pariatur blanditiis magnam veritatis repudiandae beatae nam quae incidunt sint porro, nesciunt, et quas ullam, corrupti adipisci repellat quo."
    
    reliable_send(sock, server_address, fullmessage)

    sock.close()
