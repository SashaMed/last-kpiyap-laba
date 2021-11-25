#pragma once
#include"Header.h"
#include"EmployerHeader.h"
#include"TouristHeader.h"

class Business : public Employer, public Tourist {
protected :
	unsigned int length;
	string  *buyAddress;
public:
	Business() { length = 0; buyAddress = nullptr; }
	Business(int n) { this->length = n; buyAddress = new string[n]; }
	Business(string s[], int n);
	Business(const Business& obj) {
		//Business temp(obj.length);
		this->buyAddress = new string[obj.length];
		this->length = obj.length;
		for (int i = 0; i < length; i++) {
			this->buyAddress[i] = obj.buyAddress[i];
		}
	}



	//Business(const Business& obj);
	~Business() { delete[] this->buyAddress; }
	
	bool operator >(const Business& obj) {
		if (this->length > obj.length) return true;
		return false;
	}

	void printShapka() {

	}


	bool operator ==(const Business& obj) {
		if (this->length != obj.length) return false;
		for (int i = 0; i < length; i++) {
			if (this->buyAddress[i] != obj.buyAddress[i]) return false;
		}
		return true;
	}

	void operator=(const Business& obj) {
		//Business temp(obj.length);
		this->buyAddress = new string[obj.length];
		for (int i = 0; i < length; i++) {
			this->buyAddress[i] = obj.buyAddress[i];
		}
	}


	string* getBuyAddresses();
	string getBuyAddress(int n);

	void setAddresses(string s[], int n);
	void setAddress(string s, int n = 0);

	friend ostream& operator << (ostream& out, const Business &obj);
	friend istream& operator >> (istream& in, Business& obj);
};