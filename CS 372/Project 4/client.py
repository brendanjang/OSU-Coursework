import socket

'''
CLIENT PROGRAM
'''

# HOST and PORT connection from client to server
HOST = 'localhost'
PORT = 7777

print('Connected to: ' + HOST + ' on port: ' + str(PORT))
print('Type /q to quit')
print('Enter message to send...')

# Open client socket to server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect((HOST, PORT))
    # Loop for continuous client-server communication
    while True:
        # Get message from client user
        message = input('>')
        # Send message to server
        client_socket.sendall(message.encode('UTF-8'))
        if message == '/q':
            break
        # Receive data from server
        data = client_socket.recv(1024)
        # Decode response from server
        response = data.decode('UTF-8')
        if response == '/q':
            break
        # Print response from server
        print(response)
