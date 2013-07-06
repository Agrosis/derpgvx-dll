#include <tchar.h>
#include <fstream>
#include <process.h>

#include "globals.h"

#define GMEXPORT extern "C" _declspec(dllexport)

using namespace std;

GMEXPORT void vx_init() { // unused for now
	WSAStartup(MAKEWORD(2,2), &wsa);
}

GMEXPORT void vx_destroy() { // unused for now
	WSACleanup();
}

void download(void *args) {
	dlcallback.reset();

	// to prevent cache from being used
	DeleteUrlCacheEntry(dladdress);
	HRESULT hr = URLDownloadToFile (NULL, _T(dladdress), _T(dlfile), 0, &dlcallback);
}

GMEXPORT double vx_download(char* address, char* file, double threaded) {
	dladdress = address;
	dlfile = file;

	if(threaded == 1)
		_beginthread(download, 0, (void*)0);
	else
		download((void*)0);
	
	return 0;
}

GMEXPORT double vx_download_progress() {
	return dlcallback.getProgress();
}

GMEXPORT double vx_download_total() {
	return dlcallback.getTotal();
}