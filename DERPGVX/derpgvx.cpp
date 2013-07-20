#include <tchar.h>
#include <fstream>
#include <process.h>

#include "globals.h"
#include "crypto.h"

#define GMEXPORT extern "C" _declspec(dllexport)

using namespace std;
using std::string;

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
	return (double)dlcallback.getProgress();
}

GMEXPORT double vx_download_total() {
	return (double)dlcallback.getTotal();
}

GMEXPORT char* md5hash(char* in) {
	return (char*)md5(string(in)).c_str();
}

GMEXPORT char* vx_generate_FMOD_key(char* a, char* b) {
	string fa = md5(string(a) + string(b));
	string fb = md5(string(b) + string(a));
	string fc = md5(string(b) + string(b));

	return (char*)(fa + fb + fc).c_str();
}