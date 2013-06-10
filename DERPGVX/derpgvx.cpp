#include <tchar.h>
#include <fstream>

#include "globals.h"

#define GMEXPORT extern "C" _declspec(dllexport)

using namespace std;

GMEXPORT void vx_init() { // unused for now
	WSAStartup(MAKEWORD(2,2), &wsa);
}

GMEXPORT void vx_destroy() { // unused for now
	WSACleanup();
}

GMEXPORT double vx_download(char* address, char* file) {
	/*ofstream output("game.jar", ios::out | ios::binary);

	vxsocket* sock = new vxsocket("http://assets.jantox.com/deathsiege/game.jar", 80);
	
	char* buffer;
	int recved;
	memset(buffer, 0, BUFFER_SIZE);

	while((recved = sock->receiveData(buffer)) > 0) {
		output.write(buffer, recved);
	}

	output.close();

	sock->disconnect();*/

	HRESULT hr = URLDownloadToFile ( NULL, _T(address), _T(file), 0, NULL );

	return 0;
}
