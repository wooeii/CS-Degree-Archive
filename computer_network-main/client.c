#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 22000

int main() {
    int socket_fd;
    char send_message[BUFFER_SIZE];
    char recv_message[BUFFER_SIZE];

    struct sockaddr_in server_addr;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));

    connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    bzero(send_message, BUFFER_SIZE);
    bzero(recv_message, BUFFER_SIZE);

    fgets(send_message, BUFFER_SIZE, stdin);
    write(socket_fd, send_message, strlen(send_message)+1);
    read(socket_fd, recv_message, BUFFER_SIZE);
    printf("%s", recv_message);

    return 0;
}
