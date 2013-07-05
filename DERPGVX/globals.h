#ifndef GLOBALS_H
#define GLOBALS_H

#include "dlcallback.h"

#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

extern WSAData wsa;

extern DownloadCallback dlcallback;

extern char *dladdress, *dlfile;

#endif