#client.py
import socket
import threading
import sys

class ChatClient:
    def __init__(self, host="127.0.0.1", port=5555):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((host, port))
        server_prompt = self.client.recv(1024).decode("utf-8")
        print(server_prompt, end="")
        self.username = input()
        self.client.send(self.username.encode("utf-8"))

    def receive_messages(self):
        while True:
            try:
                message = self.client.recv(4096).decode("utf-8")
                if message.startswith("DM from "):
                    print("\r" + message)
                elif message.startswith("FILE:"):
                    parts = message.split("\n", 1)
                    if len(parts) == 2:
                        filename = parts[0][5:]
                        file_content = parts[1]
                        print(f"\nReceived file '{filename}':\n{file_content}\n")
                else:
                    print("\r" + message)
                sys.stdout.write(f"{self.username}: ")
                sys.stdout.flush()
            except:
                print("Disconnected from server.")
                self.client.close()
                break

    def send_message(self, message):
        self.client.send(message.encode("utf-8"))

    def start(self):
        threading.Thread(target=self.receive_messages, daemon=True).start()
        try:
            while True:
                sys.stdout.write(f"{self.username}: ")
                sys.stdout.flush()
                message = input()
                if message.lower() == "exit":
                    self.client.close()
                    break
                else:
                    self.send_message(message)
        except KeyboardInterrupt:
            print("\nExiting chat...")
            self.client.close()
            sys.exit()

if __name__ == "__main__":
    client = ChatClient()
    client.start()
