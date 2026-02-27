from socket import *

serverPort = 12000
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind(('localhost',serverPort))

print('The server is ready to receive')

while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    result = message.decode().upper()
    serverSocket.sendto(result.encode(), clientAddress)
