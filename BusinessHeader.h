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
		this->buyAddress = new string[obj.length];
		this->length = obj.length;
		for (int i = 0; i < length; i++) {
			this->buyAddress[i] = obj.buyAddress[i];
		}
	}



	//Business(const Business& obj);
	~Business() { /*delete[] this->buyAddress;*/ };
	
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
		this->length = obj.length;
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

	friend ostream& operator << (ofstream& out, const Business obj) {
		out << obj.length;
		out << "\n";
		for (int i = 0; i < obj.length; i++) {
			out << setw(15);
			out << obj.buyAddress[i];
		}
		out << "\n";
		return out;
	}

	friend ifstream& operator >> (ifstream& in, Business& obj){
		FuncClass func; char c;
		const int size = 16;
		char* buf = new char[size];
		in >> obj.length;
		in.get();
		obj.buyAddress = new string[obj.length];
		for (int i = 0; i < obj.length; i++) {
			in.getline(buf, size);
			in.clear();
			obj.buyAddress[i] = func.sdvig(buf);
		}
		//c = in.get();
		return in;
	}


	friend fstream& operator << (fstream& out, const Business obj) {
		const char* buf = new char[15];
		int temp = obj.length;
		out.write(reinterpret_cast <char*>( &temp), sizeof(int));
		for (int i = 0; i < obj.length; i++) {
			//out << setw(15);
			//out << obj.buyAddress[i];
			buf = obj.buyAddress[i].c_str();
			out.write(buf, sizeof(buf));
			//out.write(reinterpret_cast <char *>(&obj.buyAddress[i]), sizeof(obj.buyAddress[i]));
		}
		return out;
	}


	friend fstream& operator >> (fstream& out, Business &obj) {
		char* buf = new char[15];
		int temp = 0;
		out.read((char*)&temp, sizeof(int));
		obj.length = temp;
		obj.buyAddress = new string[temp];
		for (int i = 0; i < obj.length; i++) {
			out.read(buf, sizeof(buf));
			obj.buyAddress[i] = buf;
			//obj.buyAddress[i].reserve(15);  // or some other size
			//invFile.read(itemName.c_str(), itemName.capacity());
			//out.read(obj.buyAddress[i].c_str(), obj.buyAddress[i].capacity());
			//out.read(reinterpret_cast <char*>(&obj.buyAddress[i]),sizeof( char[15]));

		}
		return out;
	}
};