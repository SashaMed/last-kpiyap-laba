#pragma once
#include"Header.h"


class Tourist : public Human {
protected:
	string passNum;
	struct {
		string date;
		string country;
	}borderStruct;
public:
	Tourist() { passNum = '\0'; borderStruct.date = '\0'; borderStruct.country = '\0'; };
	Tourist(string pn, string d, string c) { passNum = pn; borderStruct.date = d; borderStruct.country = c; };
	~Tourist() {};

	

	string getName();
	string getSurName();
	string getBirthDate();
	void setName(string n);
	void setSurName(string sn);
	void setBirthDate(string bd);

	string getPassNum();
	string getBorDate();
	string getBorCoun();
	void setPassNum(string n);
	void setBorDate(string n);
	void setBorCoun(string n);


	void printShapka() {
		cout << "passNum" << setw(15) << "date" << setw(15) << "country" << endl;
	};

	friend ostream& operator << (ostream& out, const Tourist obj);
	friend istream& operator >> (istream& in, Tourist& obj);

	bool operator >(const Tourist& obj);
	Tourist operator =(const Tourist &obj);
	Tourist(const Tourist& obj) {
		passNum = obj.passNum; 
		borderStruct.date = obj.borderStruct.date;
		borderStruct.country = obj.borderStruct.country;
	}

	bool operator ==(const Tourist& obj) {
		if (passNum == obj.passNum &&
			borderStruct.date == obj.borderStruct.date &&
			borderStruct.country == obj.borderStruct.country) return true;
		return false;
	}
};