# socket code to send two numbers to the server and receive their sum from input
import socket

def send_numbers(num1, num2):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('localhost', 8080))
    s.send(f"{num1} {num2}".encode())
    response = s.recv(1024).decode()
    print("Server response:", response)
    s.close()


if __name__ == "__main__":
    number1 = int(input("Enter first number: "))
    number2 = int(input("Enter second number: "))
    send_numbers(number1, number2)