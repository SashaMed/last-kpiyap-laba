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

	class Compator {
	public:
		bool operator()(const Employer& obj, const Employer& obj1) {
			return obj.regNum > obj1.regNum;
		}
	};

	Employer() : Human() { 
		regNum = "\0"; 
		regAddress = "\0"; 
		payStruct.payDate = "\0"; 
		payStruct.sum = -1; 
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


	Employer operator =(const Employer& obj);/* {
		if (this->payStruct.sum > obj.payStruct.sum) return true;
		return false;
	}*/
	bool operator >(const Employer &obj);

	bool operator ==(const Employer& obj) {
		if(obj.regAddress != "\0")
		if (this->regAddress != obj.regAddress) {
			return false;
		}
		if (obj.regNum != "\0")
			if (this->regNum != obj.regNum) {
				return false;
			}

		if (obj.payStruct.payDate != "\0")
			if (this->payStruct.payDate != obj.payStruct.payDate) {
				return false;
			}
		if (obj.payStruct.sum != -1)
			if (this->payStruct.sum != obj.payStruct.sum) {
				return false;
			}
		return true;

		//if (this->regAddress == obj.regAddress && this->regNum == obj.regNum &&
		//	this->payStruct.payDate == obj.payStruct.payDate &&
		//	this->payStruct.sum == obj.payStruct.sum) return true;
		//return false; 
	}
	
	void printShapka() {
		cout << setw(15) << "REG NUM" << setw(15) << "REG ADDRESS" << setw(15) << "PAY DATE"<< setw(15)<<"PAY SUM" << endl;
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

	Employer choose();

	friend ostream& operator << (ostream& out,const Employer obj);
	friend istream& operator >> (istream& in, Employer &obj);
	
	friend ostream& operator << (ofstream& out, const Employer obj);
	friend ifstream& operator >> (ifstream& in, Employer& obj);


	friend fstream& operator << (fstream& out, Employer& obj);
	friend fstream& operator >> (fstream& in, Employer& obj);
};



