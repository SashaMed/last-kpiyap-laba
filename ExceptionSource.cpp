#include"ExceptionHeader.h"
#include<math.h>


int InputCheak::intInput(istream& in) {
	bool fl = 0;
	int temp;
	do {
		try {
			fl = 0;
			rewind(stdin);
			in >> temp;

			if (!in) {
				throw Exception("invalid input");
			}

			if (cin.get() != '\n') {
				throw Exception("invalid input");
			}

			if (temp < 0) {
				throw Exception("invalid input, value < 0");
			}
		}
		catch (Exception &exc) {
			cout << exc.getErr() << endl;
			fl = 1;
			cin.clear();
		}


	} while (fl);
	return temp;
}

int InputCheak::intInput(istream& in, int lowerLim , int upperLim ) {
	bool fl = 0;
	int temp;
	do {
		try {
			fl = 0;
			temp = intInput(in);
			if (temp < lowerLim || temp > upperLim) {
				throw Exception("value out of limits");
			}
		}
		catch (Exception& exc) {
			cout << exc.getErr() << endl;
			fl = 1;
		}
	} while (fl);
	
	return temp;
}


string InputCheak::stringInput(istream& in) {
	bool fl = 0;
	string temp;
	do {
		try {
			fl = 0;
			rewind(stdin);
			in >> temp;
			for (int i = 0; i < temp.length(); i++) {
				if (!(temp[i] >='A' && temp[i] <= 'Z') && !(temp[i] >= 'a' && temp[i] <= 'z') &&
					 !(temp[i] >= '0' && temp[i] <= '9')) {
					throw Exception("invalid input");
				}
			}

		}
		catch (Exception& exc) {
			cout << exc.getErr() << endl;
			fl = 1;
			cin.clear();
		}


	} while (fl);


	return temp;

}