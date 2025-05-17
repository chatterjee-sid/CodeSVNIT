#server.py
import socket
import threading
import os

class ChatServer:
    def __init__(self, host="127.0.0.1", port=5555):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((host, port))
        self.server.listen(5)
        print(f"Server started on {host}:{port}")
        self.clients = {}
        self.usernames = {}

    def broadcast(self, message, sender_socket=None):
        for client in self.clients.keys():
            if client != sender_socket:
                try:
                    client.send(message)
                except:
                    client.close()
                    del self.clients[client]
                    del self.usernames[client]

    def send_to_specific(self, message, recipient_username):
        recipient_socket = None
        for client, username in self.usernames.items():
            if username == recipient_username:
                recipient_socket = client
                break

        if recipient_socket:
            try:
                recipient_socket.send(message)
            except:
                recipient_socket.close()
                del self.clients[recipient_socket]
                del self.usernames[recipient_socket]

    def send_file(self, sender_socket, recipient_username, filename):
        if not os.path.exists(filename):
            sender_socket.send(f"File '{filename}' not found.".encode("utf-8"))
            return

        with open(filename, "r") as f:
            file_content = f.read()

        message = f"[FILE] {filename}\n{file_content}"

        if recipient_username == "all":
            self.broadcast(message, sender_socket)
        else:
            recipient_socket = next((c for c, u in self.usernames.items() if u == recipient_username), None)
            if recipient_socket:
                recipient_socket.send(message.encode("utf-8"))
            else:
                sender_socket.send(f"User '{recipient_username}' not found.".encode("utf-8"))

    def handle_client(self, client_socket, addr):
        client_socket.send(b"Enter your username: ")
        username = client_socket.recv(1024).decode("utf-8").strip()
        
        self.clients[client_socket] = addr
        self.usernames[client_socket] = username
        print(f"{username} connected from {addr}")
        
        join_message = f"{username} has joined the chat.".encode("utf-8")
        self.broadcast(join_message)

        while True:
            try:
                message = client_socket.recv(1024).decode("utf-8")
                if not message:
                    break
                
                if message.startswith("@"):
                    parts = message.split(" ", 1)
                    if len(parts) > 1:
                        recipient = parts[0][1:]
                        msg_content = parts[1]
                        dm_message = f"DM from {username}: {msg_content}".encode("utf-8")
                        self.send_to_specific(dm_message, recipient)

                elif message.startswith("/file"):
                    parts = message.split(" ", 2)
                    if len(parts) >= 3:
                        recipient = parts[1][1:]
                        filename = parts[2]

                        try:
                            with open(filename, "r") as f:
                                file_content = f.read()

                            file_message = f"FILE:{filename}\n{file_content}".encode("utf-8")
                            
                            if recipient == "all":
                                self.broadcast(file_message)
                            else:
                                self.send_to_specific(file_message, recipient)

                        except FileNotFoundError:
                            client_socket.send(f"Error: File '{filename}' not found.".encode("utf-8"))

                else:
                    formatted_message = f"{username}: {message}".encode("utf-8")
                    print(formatted_message.decode("utf-8"))
                    self.broadcast(formatted_message,client_socket)
            except:
                break

        del self.clients[client_socket]
        del self.usernames[client_socket]
        client_socket.close()
        
        print(f"{username} has left the chat.")
        leave_message = f"{username} has left the chat.".encode("utf-8")
        self.broadcast(leave_message)

    def remove_client(self, client_socket):
        if client_socket in self.clients:
            del self.clients[client_socket]
        if client_socket in self.usernames:
            username = self.usernames.pop(client_socket)
            print(f"{username} disconnected.")
            self.broadcast(f"{username} has left the chat.".encode("utf-8"), sender_socket=None)

    def run(self):
        while True:
            client_socket, addr = self.server.accept()
            threading.Thread(target=self.handle_client, args=(client_socket, addr)).start()

if __name__ == "__main__":
    server = ChatServer()
    server.run()