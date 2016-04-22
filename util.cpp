#include "headers/util.h"


int recvn(SOCKET fd, char *bp, size_t len) {
	return recv(fd, bp, len, MSG_WAITALL);
}

void writeToLog(std::string message){
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	ofstream(log);
	log.open("log.txt", ios_base::app);
	log << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday << '-'
		<< now->tm_hour << ':'
		<< now->tm_min
		<< "  ";
	log << message << endl;
	log.close();
}

int sendn(SOCKET s, char* buf, int lenbuf, int flags) {
	int bytesSended = 0; //
	int n; //
	while (bytesSended < lenbuf)  {
		n = send(s, buf + bytesSended, lenbuf - bytesSended, flags);
		if (n < 0) {
			cout<<("Error with send in sendn\n");
			break;
		}
		bytesSended += n;
	}
	return (n == -1 ? -1 : bytesSended);
}

int recvLine(SOCKET sock, char* buffer, int buffSize) { //функция приема сообщения 
	char* buff = buffer; //указатель на начало внешнего буфера 
	char* currPosPointer; //указатель для работы со временным буфером 
	int count = 0; //число прочитанных символов (без удаления из буфера сокета) 
	char tempBuf[100]; //временный буфер для приема
	char currChar; //текущий анализируемый символ (ищем разделитель)
	int tmpcount = 0;
	while (--buffSize > 0){
		if (--count <= 0) {
			recvn(sock, tempBuf, tmpcount);
			count = recv(sock, tempBuf, sizeof (tempBuf), MSG_PEEK);
			if (count <= 0) { return count; }
			currPosPointer = tempBuf;
			tmpcount = count;
		}
		currChar = *currPosPointer++;
		*buffer++ = currChar;
		if (currChar == '\n') {
			*(buffer - 1) = '\0';
			recvn(sock, tempBuf, tmpcount - count + 1);
			return buffer - buff - 1;
		}
	}
	return -1;
}

int sendLine(int sock, const char* str) {
	char tempBuf[MAX_STR_LEN];
	strcpy(tempBuf, str);
	if (tempBuf[strlen(tempBuf) - 1] != '\n')
		strcat(tempBuf, "\n");
	return sendn(sock, tempBuf, strlen(tempBuf), 0);
}

static inline bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
	string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i <4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';

	}

	return ret;

}

string base64_decode(string const& encoded_string) {
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i <4; i++)
				char_array_4[i] = base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j <4; j++)
			char_array_4[j] = 0;

		for (j = 0; j <4; j++)
			char_array_4[j] = base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}