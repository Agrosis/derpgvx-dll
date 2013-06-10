#include "vxsocket.h"

#include <ws2tcpip.h>

vxsocket::vxsocket(char* address, int port) {
	this->address = address;
	this->port = port;
}

int vxsocket::setup() {
	struct addrinfo hints, *res;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if(getaddrinfo(this->address, "80", &hints, &res) != 0) {
		return -1;
	}

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if(sockfd == -1) {
		return -1;
	}

	int resc = connect(sockfd, res->ai_addr, res->ai_addrlen);
	if(resc == -1) {
		return -1;
	}
}

int vxsocket::receiveData(char* buffer) {
	return recv(this->sockfd, buffer, BUFFER_SIZE, 0);
}

void vxsocket::disconnect() {
	closesocket(sockfd);
}
