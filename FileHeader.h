#pragma once
#include"Header.h"



class File {
protected:
	ofstream out;
	ifstream in;
	fstream fstr;
public:
	string path;
	File(string n) { path = n; }
};


template<typename valueType>
class TFile : public File {
public:
	TFile(string n) :File(n) {};
	~TFile() {
		if (out.is_open()) { out.close(); }
		if (in.is_open()) { in.close(); }
		if (fstr.is_open()) { fstr.close(); }
	}
	bool open(string path, unsigned int mode) {
		switch (mode)
		{
		case 1:
			out.open(path);
			if (out.is_open()) return true;
			return false;
		case 2:
			in.open(path);
			if (in.is_open()) return true;
			return false;
		case 3:
			fstr.open(path, ofstream::app);
			if (fstr.is_open()) return true;
			return false;
		default:
			break;
		}
	}

	valueType read() {
		if (!in.is_open()) {
			in.open(path);
		}
		valueType buf;
		in >> buf;
		return buf;
	}

	valueType read(string p) {
		if (!in.is_open()) {
			in.open(p);
		}
		valueType buf;
		in >> buf;
		in.close();
		return buf;
	}


	void write(valueType obj) {
		if (!fstr.is_open()) {
			fstr.open(path);
		}
		fstr << obj;
	}

	void Outclose() {
		fstr.close();
	}

	void Inclose() {
		in.close();
	}

	bool InEof() {
		if (in.eof()) return true;
		return false;
	}

};




template<typename valueType>
class BFile : public File {
public:
	
	BFile(string n, int mode) :File(n) {
		fstr.open(path, ios_base::binary);
		switch (mode) {
		case 1:
			fstr.open(n, ios::trunc | ios::in | ios::out | ios::binary);
			break;
		case 2:
			fstr.open(n, ios::in | ios::binary);
			break;
		case 3:
			fstr.open(n, ios::app | ios::binary);
			break;
		default:
			cout << "\ninvalid mode\n";
			break;
		}
	};

	~BFile() {
		if (fstr.is_open())
			fstr.close();
	}
	void close() {
		fstr.close();
	}
	bool InEof() {
		if (fstr.eof()) return true;
		return false;
	}

	void write(valueType n) {
		fstr << n;
	}

	valueType read() {
		valueType temp;
		fstr >> temp;
		return temp;
	}
	bool eof() {
		if (fstr.eof() == true) return true;
		return false;
	}

};