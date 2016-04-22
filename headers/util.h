#ifndef SERVER_UTIL_H
#define SERVER_UTIL_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define MAX_STR_LEN 4096
#define SIZE_OF_BUF 4096
#define numCl 2

static const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

void writeToLog(string message);
int recvn(SOCKET fd, char *bp, size_t len);
int sendn(SOCKET s, char* buf, int lenbuf, int flags);
int recvLine(SOCKET sock, char* buffer, int buffSize);
int sendLine(int sock, const char* str);
string base64_encode(unsigned char const*, unsigned int len);
string base64_decode(string const& s);
#endif /*SERVER_UTIL_H*/