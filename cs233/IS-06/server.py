import http.server
import ssl

PORT = 33281
server_address = ('127.0.0.1', PORT)

handler = http.server.SimpleHTTPRequestHandler
httpd = http.server.HTTPServer(server_address, handler)

context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
context.load_cert_chain(certfile="selfsigned.crt", keyfile="selfsigned.key")

httpd.socket = context.wrap_socket(httpd.socket, server_side=True)

print(f"Serving HTTPS on https://127.0.0.1:{PORT}")

try:
    httpd.serve_forever()
except KeyboardInterrupt:
    print("\nShutting down server...")
    httpd.server_close()
