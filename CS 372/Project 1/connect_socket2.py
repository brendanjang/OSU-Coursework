from socket import*

# get ip of host to connect to
host_ip = gethostbyname('gaia.cs.umass.edu')
serverName = 'gaia.cs.umass.edu'

# port to use
serverPort = 80

# use try/except statement to make sure socket has been created
try:
    clientSocket = socket(AF_INET, SOCK_STREAM)
    # print ("Socket created successfully")
except socket.error as err:
    print("Socket creation failed with error %s" % err)

# connect function using previously declared parameters
clientSocket.connect((host_ip, serverPort))

# send GET request to host and print return data
req = "GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1\r\nHost:gaia.cs.umass.edu\r\n\r\n"

print("Request: ", req)

# encode Unicode strings to byte strings inspired from
# https://stackoverflow.com/questions/42612002/python-sockets-error-typeerror-a-bytes-like-object-is-required-not-str-with
clientSocket.send(req.encode('utf-8'))

""" 
use conditional loop to determine when recv or read return <= 0 bytes
inspired from https://stackoverflow.com/questions/17667903/python-socket-receive-large-amount-of-data
"""
while True:
    # store response from host
    modifiedSentence = clientSocket.recv(1024)
    print(modifiedSentence)
    if not modifiedSentence:
        break

# close connection
clientSocket.close()