import sys
import socket
from urllib.parse import urlparse

def main():
    if len(sys.argv) != 2:
        print("Usage: python py_web_curl.py URL")
        sys.exit(1)

    url_parse = urlparse(sys.argv[1])

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    netloc = url_parse.netloc
    sock.connect((netloc, 80))

    path = '/' if url_parse.path == '' else url_parse.path

    msg = "GET " + path + " HTTP/1.1\r\nHost:" + netloc + "\r\n"
    msg += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36"
    msg += "\r\n\r\n"
    request_msg = bytes(msg, encoding='utf8')
    print(request_msg)
    sock.send(request_msg)

    response_msg = b''
    while True:
        temp = sock.recv(1024)
        if b'</html>' in temp:
            response_msg += temp
            break
        response_msg += temp

    print(response_msg.decode(encoding='utf8'))
    sock.close()

if __name__ == "__main__":
    main()