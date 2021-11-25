#pragma once
#include"Header.h"


class Employer : public Human {
protected:
	string regNum;
	string regAddress;
	struct {
		string payDate;
		long int sum  = 0;
	}payStruct;
public:
	Employer() :Human() { 
		regNum = '\0'; 
		regAddress = '\0'; 
		payStruct.payDate = '\0'; 
		payStruct.sum = 0; 
	};

	Employer(string n, string ad, string date, int sum):Human() { 
		regNum = n; 
		regAddress = ad; 
		payStruct.payDate = date; 
		payStruct.sum = sum; 
	};

	~Employer() {};
	Employer(const Employer& obj) {
		this->payStruct.sum = obj.payStruct.sum;
		this->payStruct.payDate = obj.payStruct.payDate;
		this->regNum = obj.regNum;
		this->regAddress = obj.regAddress;
	};


	Employer operator = (const Employer& obj);
	bool operator >(const Employer &obj);
	bool operator ==(const Employer& obj) {
		if (this->regAddress == obj.regAddress && this->regNum == obj.regNum &&
			this->payStruct.payDate == obj.payStruct.payDate &&
			this->payStruct.sum == obj.payStruct.sum) return true;
		return false; 
	}
	
	void printShapka() {
		cout << "regNumr" << setw(15) << "egAddress" << setw(15) << "payDate"<< setw(15)<<"paySum" << endl;
	};

	string getName();
	string getSurName();
	string getBirthDate();
	void setName(string n);
	void setSurName(string sn);
	void setBirthDate(string bd);


	string getRegNum();
	string getRegAd();
	string getPayhDate();
	long int getPaySum();
	void setRegNum(string n);
	void setRegAd(string sn);
	void setPayDate(string bd);
	void setPaySum(long int bd);

	friend ostream& operator << (ostream& out,const Employer obj);
	friend istream& operator >> (istream& in, Employer &obj);
};



