#include"EmployerHeader.h"


string Employer::getName() {
	return this->name;
}

string Employer::getSurName() {
	return this->surName;
}

string Employer::getBirthDate() {
	return this->birthDate;
}



void Employer::setName(string n) {
	this->name = n;
}

void Employer::setSurName(string sn) {
	this->surName = sn;
}

void Employer::setBirthDate(string n) {
	this->birthDate = n;
}



string Employer::getPayhDate() {
	return this->payStruct.payDate;
}

long int Employer::getPaySum() {
	return this->payStruct.sum;
}

string Employer::getRegAd() {
	return this->regAddress;
}

string Employer::getRegNum() {
	return this->regNum;
}




void Employer::setPayDate(string n) {
	this->payStruct.payDate = n;
}

void Employer::setPaySum(long int n) {
	this->payStruct.sum = n;
}

void Employer::setRegAd(string n) {
	this->regAddress = n;
}

void Employer::setRegNum(string n) {
	this->regNum = n;
}


ostream& operator << (ostream& out,const Employer obj) {
	out << setw(15);
	out << obj.regNum; 
	out << setw(15);
	out << obj.regAddress;
	out << setw(15);
	out << obj.payStruct.payDate;
	out << setw(15);
	out << obj.payStruct.sum;
	return out;
}



istream& operator >> (istream& in, Employer &obj) {
	InputCheak temp;
	obj.regNum = temp.stringInput(in);
	obj.regAddress = temp.stringInput(in);
	obj.payStruct.payDate = temp.stringInput(in);
	obj.payStruct.sum = temp.intInput(in, 0);
	return in;
}

ostream& operator << (ofstream& out, const Employer obj) {
	//char str[10];
	//stringToChar(obj.regNum, str);
	//out << str;
	//stringToChar(obj.regAddress, str);
	//out << str;
	//stringToChar(obj.payStruct.payDate, str);
	//out << str;
	//out << obj.payStruct.sum;
	out << setw(15);
	out << obj.regNum;
	out << setw(15);
	out << obj.regAddress;
	out << setw(15);
	out << obj.payStruct.payDate;
	out << setw(15);
	out << obj.payStruct.sum;
	out << endl;
	return out;
}



ifstream& operator >> (ifstream& in, Employer& obj) {
	FuncClass func;
	string temp;
	const int size = 16;
	char *buf = new char[size];
	in.getline(buf, size);
	in.clear();
	obj.regNum = func.sdvig(buf);
	in.getline(buf, size);
	in.clear();
	obj.regAddress = func.sdvig(buf);
	in.getline(buf, size);
	in.clear();
	obj.payStruct.payDate = func.sdvig(buf);
	in >> obj.payStruct.sum;
	in.get();
	return in;
}


bool Employer::operator>(const Employer& obj) {
	if (this->payStruct.sum > obj.payStruct.sum) return true;
	return false;
}


Employer Employer::operator =(const Employer& obj)
{
	this->payStruct.sum = obj.payStruct.sum;
	this->payStruct.payDate = obj.payStruct.payDate;
	this->regNum = obj.regNum;
	this->regAddress = obj.regAddress;
	return *this;
}


Employer Employer::choose() {
	int n;
	Employer t;
	string str;
	cout << "1.reg ad. 2.reg num. 3. pay date. 4. pay sum. 5. exit\n";
	cin >> n;
	while (1) {
		switch (n) {
		case 1:
			cin >> str;
			t.setRegAd(str);
			break;
		case 2:
			cin >> str;
			t.setRegNum(str);
			break;
		case 3:
			cin >> str;
			t.setPayDate(str);
			break;
		case 4:
			cin >> n;
			t.setPaySum(n);
			break;
		case 5:
			return t;
		default:
			return t;
		}
	}
}


fstream& operator << (fstream& out, Employer& obj) {
	const char* buf = new char[30];
	int temp;
	buf = obj.regNum.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE);
	buf = obj.regAddress.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE);
	buf = obj.payStruct.payDate.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE);
	temp = obj.payStruct.sum;
	out.write(reinterpret_cast <char*>(&temp), sizeof(int));
	return out;
}


fstream& operator >> (fstream& in, Employer& obj) {
	char* buf = (char*)calloc(30, sizeof(char));
	int temp;
	
	in.read(buf, SIZE);
	if (buf == "")return in;
	obj.regNum = buf;

	in.read(buf, SIZE);
	obj.regAddress = buf;
	in.read(buf, SIZE);
	obj.payStruct.payDate = buf;
	in.read((char*)&temp, sizeof(int));
	obj.payStruct.sum = temp;
	return in;
}
