//этот заголовочный файл при компил€ции будет подключен только один раз
#pragma once
#include <string>
class Letter
{
public:
	Letter();
	~Letter();
	
	void addFrom(std::string& fr){
		from = fr;
	}

	void addSubject(std::string& sub){
		subject = sub;
	}

	void addData(std::string& dat){
		data += dat;
	}

	void addTo(std::string& t){
			to = t;
	}

	std::string getFrom(){
		return from;
	}

	std::string getData(){
		return data;
	}

	std::string getTo(){
		return to;
	}

	std::string getSubject(){
		return subject;
	}
private:
	std::string from;
	std::string to;
	std::string subject;
	std::string data;
};

