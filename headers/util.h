#ifndef SMTPSERVER_UTIL_H
#define SMTPSERVER_UTIL_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define MAX_STR_LEN 4096
#define SIZE_OF_BUF 4096
#define numCl 2

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

void writeToLog(std::string message);
int recvn(SOCKET fd, char *bp, size_t len);
int sendn(SOCKET s, char* buf, int lenbuf, int flags);
int recvLine(SOCKET sock, char* buffer, int buffSize);
int sendLine(int sock, const char* str);
std::string base64_encode(unsigned char const*, unsigned int len);
std::string base64_decode(std::string const& s);
#endif /*SMTPSERVER_UTIL_H*/