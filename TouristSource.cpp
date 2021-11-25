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