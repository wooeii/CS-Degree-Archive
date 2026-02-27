#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define PORT 22000

int main() {
	char message[BUFFER_SIZE];
	int listen_fd, comm_fd;

	struct sockaddr_in server_addr;

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);
	bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	listen(listen_fd, 1);

	comm_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);

	while (1) {
		bzero(message, BUFFER_SIZE);
		read(comm_fd, message, BUFFER_SIZE);
		printf("Echoing back - %s", message);
		write(comm_fd, message, strlen(message) + 1);
	}
	return 0;
}