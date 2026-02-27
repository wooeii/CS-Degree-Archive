# resolve dns name to ip address

import socket

def resolve_dns_name(dns_name):
    try:
        ip_address = socket.gethostbyname(dns_name)
        return ip_address
    except Exception as e:
        print(e)
        return None

if __name__ == '__main__':
    print(resolve_dns_name('www.google.com'))
    print(resolve_dns_name('www.gwnu.ac.kr'))