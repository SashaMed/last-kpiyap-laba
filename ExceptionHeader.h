#pragma once
#include"Header.h"
using namespace std;

class InputCheak {
protected:
public:
	InputCheak() {};
	~InputCheak() {};
	int intInput(istream &in);
	int intInput(istream& in, int lowerLim , int upperlim = 10000000);
	string stringInput(istream& in);
};


class Exception
{
protected:
	string errName;
public:
	Exception() {};
	Exception(string s) { errName = s; }
	~Exception() {};

	void setErr(string s) {errName = s; }
	string getErr() { return errName; }
};