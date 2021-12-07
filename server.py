import socket
address = ('10.229.115.149', 5003)  
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(address)  
s.listen(5)
conn, addr = s.accept()  
print('[+] Connected with', addr)

data = conn.recv(1024)  
data = data.decode()
print('[Received]', data)

conn.close()
s.close()
