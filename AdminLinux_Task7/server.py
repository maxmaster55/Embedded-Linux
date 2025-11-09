import socket


try: 
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    print ("Socket successfully created")
except socket.error as err: 
    print ("socket creation failed with error %s" %(err))

port = 8080

s.bind(('', port))
print ("socket binded to %s" %(port)) 
s.listen(5)
print ("socket is listening")


# a loop to get two numbers and send back their sum
while True:
    c, addr = s.accept()     
    print ('Got connection from', addr )
    
    data = c.recv(1024).decode()
    print("Received data:", data)
    
    try:
        num1, num2 = map(int, data.split())
        result = num1 + num2
        response = f"The sum is: {result}"
    except ValueError:
        response = "Invalid input. Please send two integers separated by space."
    except Exception as e:
        response = f"An error occurred: {str(e)}"
    
    c.send(response.encode())
    c.close()