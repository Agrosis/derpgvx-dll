#ifndef VXSOCKET_H
#define VXSOCKET_H

#include <WinSock2.h>

#define BUFFER_SIZE 1024

class vxsocket {
public:
	vxsocket(char*, int);
	~vxsocket();

	int setup();
	void disconnect();

	int receiveData(char*);

	char* getAddress() { return address; };
	int getPort() { return port; };
private:
	SOCKET sockfd;

	char* address;
	int port;
};

#endif