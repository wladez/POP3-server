#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "headers/util.h"
#include "headers/MailHandler.h"

using namespace std;

HANDLE mutex;
HANDLE allhandlers[numCl];
int numClients = 0;

int main(void) {
	MailHandler mh;
	//������������ ��� ������������� ���������� ������� 
	char buf[SIZE_OF_BUF]; //����� ������ � �������� ��������� 
	int readbytes; //����� ����������� ���� 
	WSADATA WSStartData; //������������� WinSock � �������� ��� ������� 
	if (WSAStartup(MAKEWORD(2, 0), &WSStartData) != 0) {
		printf("WSAStartup failed with error: %d\n", GetLastError());
		return 100;
	} //�������� ������ 
	SOCKET server_socket; //�� ��������� ������������ �������� tcp 
	printf("Server is started.\nTry to create socket -----------------");
	if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("error with creation socket. GetLasterror= %d\n", GetLastError());
		return 1000;
	}
	printf("CHECK\n"); //������������ ������ ����������� IP � ������ �����
	struct sockaddr_in sin;
	sin.sin_addr.s_addr = INADDR_ANY; // ���������� ��� ����������
	sin.sin_port = htons(110); // ���������� ���� ��������� POP3
	sin.sin_family = AF_INET; printf("Try to bind socket -------------------");
	if (::bind(server_socket, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("error with bind socket. GetLasterror= %d\n", GetLastError());
		return 1001;
	}
	printf("CHECK\n"); //������ ����� ��������������
	printf("Try to set socket listening ----------");
	if (listen(server_socket, 5) != 0) {
		printf("error with listen socket. GetLasterror= %d\n", GetLastError());
		return 1002;
	}
	printf("CHECK\n");
	printf("Server starts listening\n"); //���� �������. ������� ������ ���������, ������� ����� ��������� ��������� ������, 
	//������������� ���������� 
	struct sockaddr_in from;
	int fromlen = sizeof(from); // �������� "�������" �������� ������� �� �����������
	int ind = 0;
	//�� ������ ����������� � ���������� ������
	while (SOCKET client_socket = accept(server_socket, (struct sockaddr*)&from, &fromlen)){
		//������ ����� �����, � ������� �������� clientHandler() �� MailHandler, 
		//detach ���������� ��� ����������� ���������� �� �������� ������
		mh.createThread((LPVOID)client_socket).detach();
		cout << "Client connect to server\n" <<endl;
	}
	closesocket(server_socket);
	return 0;
}
