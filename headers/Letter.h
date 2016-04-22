//этот заголовочный файл при компил€ции будет подключен только один раз
#pragma once
#include <string>
using namespace std;

class Letter
{
public:
	Letter();
	~Letter();
	
	void addFrom(string& fr){
		from = fr;
	}

	void addSubject(string& sub){
		subject = sub;
	}

	void addData(string& dat){
		data += dat;
	}

	void addTo(string& t){
			to = t;
	}

	string getFrom(){
		return from;
	}

	string getData(){
		return data;
	}

	string getTo(){
		return to;
	}

	string getSubject(){
		return subject;
	}
private:
	string from;
	string to;
	string subject;
	string data;
};

