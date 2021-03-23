import socket

'''
SERVER PROGRAM
'''

# HOST and PORT connection for server
HOST = 'localhost'
PORT = 7777

print('Server listening on: ' + HOST + ' on port: ' + str(PORT))

# Open server socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST, PORT))
    # Listen on server socket
    server_socket.listen()
    connection, address = server_socket.accept()
    # Connection encounterd
    with connection:
        print('Connected by ' + str(address))
        print('Waiting for message...')
        # Receive data from client
        data = connection.recv(1024)
        # Decode response from client
        response = data.decode('UTF-8')
        if response != '/q':
            # Print response from client
            print(response)
            print('Type /q to quit')
            print('Enter message to send...')
            # Loop for continuous server-client communication
            while True:
                # Get message from server user
                message = input('>')
                # Send message to client
                connection.sendall(message.encode('UTF-8'))
                if message == '/q':
                    break
                # Receive data from client
                data = connection.recv(1024)
                # Decode response from client
                response = data.decode('UTF-8')
                if response == '/q':
                    break
                # Print response from client
                print(response)
