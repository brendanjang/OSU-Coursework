from socket import*

# Lecture #15 was referenced heavily in the completion of this portion of the
# project.
serverPort = 1055

# welcoming socket
serverSocket = socket(AF_INET, SOCK_STREAM)

serverSocket.bind(('127.0.0.1', serverPort))

# server starts to listen for incoming requests
serverSocket.listen(1)

# loop forever
while 1:
    # server waits on accept() for incoming requests
    # new socket created on return
    data = "HTTP/1.1 200 OK\r\n" \
           "Content-Type: text/html; charset=UTF-8\r\n\r\n" \
           "<html>Congratulations! You've downloaded the first Wireshark lab file!</html>\r\n"
    connectionSocket, addr = serverSocket.accept()

    # read bytes from sockets
    sentence = connectionSocket.recv(1024)
    print(sentence)

    # encode Unicode strings to byte strings inspired from
    # https://stackoverflow.com/questions/42612002/python-sockets-error-typeerror-a-bytes-like-object-is-required-not-str-with
    # sent expected html data to new socket
    connectionSocket.send(data.encode('utf-8'))
    print(data)

    # close connection
    connectionSocket.close()
