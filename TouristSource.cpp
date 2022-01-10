#include"TouristHeader.h"


string Tourist::getName() {
	return this->name;
}

string Tourist::getSurName() {
	return this->surName;
}

string Tourist::getBirthDate() {
	return this->birthDate;
}



void Tourist::setName(string n) {
	this->name = n;
}

void Tourist::setSurName(string sn) {
	this->surName = sn;
}

void Tourist::setBirthDate(string n) {
	this->birthDate = n;
}



string Tourist::getPassNum() {
	return this->passNum;
}

string Tourist::getBorDate() {
	return this->borderStruct.date;
}

string Tourist::getBorCoun() {
	return this->borderStruct.country;
}



void Tourist::setPassNum(string s) {
	this->passNum = s;
}

void Tourist::setBorDate(string s) {
	this->borderStruct.date = s;
}

void Tourist::setBorCoun(string s) {
	this->borderStruct.country = s;
}



ostream& operator << (ostream& out, const Tourist obj) {
	out << setw(15);
	out << obj.passNum;
	out << setw(15);
	out << obj.borderStruct.date;
	out << setw(15);
	out << obj.borderStruct.country;
	return out;
}


istream& operator >> (istream& in, Tourist& obj) {
	InputCheak temp;
	obj.passNum = temp.stringInput(in);
	obj.borderStruct.date  = temp.stringInput(in);
	obj.borderStruct.country  = temp.stringInput(in);
	//in >> obj.passNum;
	//in >> obj.borderStruct.date;
	//in >> obj.borderStruct.country;
	return in;
}



Tourist Tourist::operator=(const Tourist& obj) {
	Tourist temp;
	//this->
	this->passNum = obj.passNum;
	this->borderStruct.date = obj.borderStruct.date;
	this->borderStruct.country = obj.borderStruct.country;
	return temp;
}



bool Tourist::operator>(const Tourist& obj) {
	if (this->borderStruct.date > obj.borderStruct.date) return true;
	return false;
}



ostream& operator << (ofstream& out, const Tourist obj) {
	out << setw(15);
	out << obj.passNum;
	out << setw(15);
	out << obj.borderStruct.date;
	out << setw(15);
	out << obj.borderStruct.country;
	out << endl;
	return out;
}



ifstream& operator >> (ifstream& in, Tourist& obj) {
	FuncClass func;
	string temp;
	const int size = 16;
	char* buf = new char[size];
	in.getline(buf, size);
	in.clear();
	obj.passNum = func.sdvig(buf);
	in.getline(buf, size);
	in.clear();
	obj.borderStruct.date = func.sdvig(buf);
	in.getline(buf, size);
	in.clear();
	obj.borderStruct.country = func.sdvig(buf);
	in.get();
	return in;
}


Tourist Tourist::choose() {
	int n;
	Tourist t;
	string str;
	cout << "1.pass num. 2. country. 3. data. 4. exit\n";
	cin >> n;
	while (1) {
		switch (n) {
		case 1:
			cin >> str;
			t.setPassNum(str);
			break;
		case 2:
			cin >> str;
			t.setBorCoun(str);
			break;
		case 3:
			cin >> str;
			t.setBorDate(str);
			break;
		case 4:
			return t;
		default:
			return t;
		}
	}
}


fstream& operator << (fstream& out,  Tourist &obj) {
	const char* buf = new char [30];
	int temp;
	buf = obj.passNum.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE);
	buf = obj.borderStruct.date.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE/*obj.borderStruct.date.size()*/);
	buf = obj.borderStruct.country.c_str();
	temp = sizeof(buf);
	out.write(buf, SIZE/*obj.borderStruct.country.size()*/);
	//out.write(reinterpret_cast <char*>(&obj.passNum), sizeof(obj.passNum));
	//out.write(reinterpret_cast <char*>(&obj.borderStruct.date), sizeof(obj.borderStruct.date));
	//out.write(reinterpret_cast <char*>(&obj.borderStruct.country), sizeof(obj.borderStruct.country));
	return out;
 }

fstream& operator >> (fstream& in, Tourist& obj) {
	char* buf = (char*)calloc(30, sizeof(char));
	int temp;
	//in.read(reinterpret_cast <char*>(&obj.passNum), sizeof(obj.passNum));
	in.read(buf, SIZE);
	if (buf == "")return in;
	obj.passNum = buf;
	//in.read(reinterpret_cast <char*>(&obj.borderStruct.date), sizeof(obj.borderStruct.date));
	in.read(buf, SIZE/*sizeof(buf)*/);
	obj.borderStruct.date = buf;
	//in.read(reinterpret_cast <char*>(&obj.borderStruct.country), sizeof(obj.borderStruct.country));
	in.read(buf, SIZE/*sizeof(buf)*/);
	obj.borderStruct.country = buf;
	return in;

 }

