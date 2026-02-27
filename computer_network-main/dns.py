import sys
import socket

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python dns.py <domain name>")
        sys.exit(1)

    try:
        result = socket.gethostbyname(sys.argv[1])
        print("IP address of domain name: ", result)
    except socket.gaierror:     # get address info error
        print("Invalid domain name")
        sys.exit(1)