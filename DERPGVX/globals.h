#ifndef GLOBALS_H
#define GLOBALS_H

#include "dlcallback.h"

#include <urlmon.h>
#include <WinInet.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

extern WSAData wsa;

extern DownloadCallback dlcallback;

extern char *dladdress, *dlfile;

#endif