#pragma once
#include <vector>
#include <string>
#include "headers/Letter.h"
class Mailbox
{
public:
	Mailbox();
	~Mailbox();
	void addLetterToMailbox(const Letter& let){
		letters.push_back(let);
	}

	void eraseLetterFromMailbox(const int& num){
		letters.erase(letters.begin() + num);
	}

	//���������� ���-�� �����
	int returnCountOfLetters(){
		return letters.size();
	}

	//���������� ������ ���� �����
	int returnSizeOfAllLetters(){
		int res = 0;
		for (int i = 0; i < letters.size();i++){
			res += sizeof(letters.at(i+1));
		}
		return res;
	}

	//���������� ������ ������
	int returnSizeOfLetter(int i){
		return sizeof(letters.at(i+1));
	}

	//���������� ������
	Letter returnLetter(int i){
		Letter l = letters.at(i-1);
		return l;
	}

	//������������� ����
	void setFlag(int i, bool b){
		letters.at(i - 1).setMarker(b);
	}

private:
	vector<Letter>letters;
};

