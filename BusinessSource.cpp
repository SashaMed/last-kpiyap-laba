#include"BusinessHeader.h"

Business::Business(string s[], int n) {
	this->length  = n;
	this->buyAddress = new string[length];
	for (int i = 0; i < length; i++) {
		this->buyAddress[i] = s[i];
	}
}

//Business::Business(const Business& obj) {
//	this->length = obj.length;
//	for (int i = 0; i < length; i++) {
//		this->buyAddress[i] = obj.buyAddress[i];
//	}
//}

string* Business::getBuyAddresses() {
	return this->buyAddress;
}

string Business::getBuyAddress(int n) {
	if (n >= this->buyAddress->length()) {
		return this->buyAddress[this->buyAddress->length() - 1];
	}
	return this->buyAddress[n];
}

void Business::setAddresses(string s[], int n) {
	delete[]this->buyAddress;
	
	this->buyAddress = new string[n];
	for (int i = 0; i < n; i++) {
		this->buyAddress[i] = s[i];
	}
}


void Business::setAddress( string s, int n ) {
	if (n >= this->buyAddress->length()) {
		return;
	}
	this->buyAddress[n-1] = s;
}

ostream& operator << (ostream& out, const Business &obj) {
	for (int i = 0; i < obj.length; i++) {
		out << setw(15) << obj.buyAddress[i] ;
	}
	return out;
}


istream& operator >> (istream& in, Business& obj) {
	
	
	
	InputCheak temp;
	if (obj.buyAddress == nullptr) {
		obj.length = temp.intInput(in);
		obj.buyAddress = new string[obj.length];
	}
	for (int i = 0; i < obj.length; i++) {
		obj.buyAddress[i] = temp.stringInput(in);
	}
	return in;
}



