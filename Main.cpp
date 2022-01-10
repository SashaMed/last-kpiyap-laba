#include"Header.h"
#include"EmployerHeader.h"
#include"TouristHeader.h"
#include"BusinessHeader.h"
#include"Source.cpp"
#include"EmployerHeader.h"
//#include"TreeHeader.h"
#include"FileHeader.h"


bool comp( Employer& obj,  Employer& obj1) {
	return obj.getRegNum() > obj1.getRegNum();

}


void print() {
	cout << "1.add value\n2.print tree\n3.delete value\n4.search value\n5.exit\n";
}

template<typename valueType>
int menu(tree<valueType> n, valueType temp) {
	int in;
	
	//valueType temp;
	while (1) {
		print();
		cin >> in;
		system("cls");
		switch (in) {
		case 1:
			cout << " input value plz\n";
			temp.printShapka();
			cin >> temp;
			n = temp;
			break;
		case 2:
			cout << "\n";
			n.output();
			cout << "\n";
			break;
		case 3:
			cout << " input value plz\n";
			cin >> temp;
			n.deleteNode(temp);
			break;
		case 4:
			cout << " input value plz\n";
			cin >> temp;
			if (n.search(temp)) cout << "true\n";
			else cout << "false\n";
			break;
		case 5:return 0;
		default: break;
		}
	}
}


Employer choose() {
	int n;
	Employer t;
	string str;
	cout << "1.reg ad. 2.reg num. 3. pay date. 4. pay sum. 5. all. 6. exit\n";

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
			cin >> t;
		case 6:
			return t;
		default:
			break;
		}
	}
}

int main()
{
	const char* empPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_employer.txt";
	const char* touristPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_tourist.txt";
	const char* businessPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_business.txt";


	const char* binEmpPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_binE.txt";
	const char* binTouristPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_binT.txt";
	const char* binBusinessPath = "D:/education/2 êóðñ/ÊÏÈßÏ/laba_8/_binB.txt";


	Employer e;
	Tourist t;
	Business b;


	tree<Employer> empTree;
	tree<Tourist> touristTree;
	tree<Business> businessTree;


	TFile<Employer> empFile(empPath);
	TFile<Tourist> touristFile(touristPath);
	TFile< Business> businessFile(businessPath);

	
	BFile<Employer> empBin(binEmpPath,1);
	BFile<Tourist> touristBin(binTouristPath,1);
	BFile< Business> businessBin(binBusinessPath,1);


	e.printShapka();
	while (!empFile.InEof()) {
		e = empFile.read();
		if (e.getPaySum() == -1) break;
		empTree = e;
		empBin.write(e);
		cout << e << endl;
	}
	empTree.output();
	empBin.close();

	t.printShapka();
	while (!touristFile.InEof()) {
		t = touristFile.read();
		touristTree = t;
		touristBin.write(t);
		cout << t << endl;
	}
	touristTree.output();
	touristBin.close();
	cout << endl;

	while (!businessFile.InEof()) {
		b = businessFile.read();
		businessBin.write(b);
		cout << b << endl;
	}
	businessBin.close();

	BFile<Employer> iempBin(binEmpPath, 2);
	BFile<Tourist> itouristBin(binTouristPath, 2);
	BFile< Business> ibusinessBin(binBusinessPath, 2);
	vector<Employer> stl;

	cout << "From binary file\n";
	e.printShapka();
	while (!iempBin.eof()) {
		e = iempBin.read();
		if (e.getRegNum() == "")break;
		stl.push_back(e);
		cout << e << endl;
	}



	iempBin.close();
	cout << endl;
	t.printShapka();
	while (!itouristBin.eof()) {
		t = itouristBin.read();
		if (t.getPassNum() == "")break;
		cout << t << endl;
	}
	itouristBin.close();



	BFile<Employer> aempBin(binEmpPath, 3);
	BFile<Tourist> atouristBin(binTouristPath, 3);
	BFile< Business> abusinessBin(binBusinessPath, 3);


	int ch = 0;
	cout << "do u want to write sm to the file?(1 to cont)\n";
	//cin >> ch;
	if (ch == 1) {

		while (1) {
			cout << "1. emp. 2. tourist. 3. business.\n";
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "input val\n";
				cin >> e;
				aempBin.write(e);
				break;
			case 2:
				cout << "input val\n";
				cin >> t;
				atouristBin.write(t);
				break;
			case 3:
				cout << "input val\n";
				cin >> b;
				abusinessBin.write(b);
				break;
			case 4:
				return 0;
			default:
				break;
			}
		}
	}
	Employer ee;
	cin >> ee;
	vector<Employer> cop;
	stl.insert(stl.begin() + 1, ee);
	for (int i = 0; i < stl.size(); i++, i++) {
		cop.push_back(stl[i]);
	}


	/*for (int i = 0; i < stl.size(); i++) {
		cout << stl[i] <<endl;
	}*/
	cout << "output by copy\n";
	stl[0].printShapka(); 
	copy(stl.begin(), stl.end(), ostream_iterator<Employer>(cout, "\n"));

	sort(stl.begin(), stl.end(), comp);
	cout << endl;
	stl[0].printShapka(); 
	for (int i = 0; i < stl.size(); i++) {
		cout << stl.at(i) << endl;
	}

	cout << "Back elem" << endl;
	cout << stl.back() << endl;
	stl.pop_back();
	cout << "Back elem after pop" << endl;
	cout << stl.back() << endl;


	cout << "Before erase\n";
	stl[0].printShapka(); 
	for (int i = 0; i < stl.size(); i++) {
		cout << stl.at(i) << endl;
	}

	cout << "After erase\n";
	stl.erase(stl.begin() + 1, stl.begin() + 3);
	for (int i = 0; i < stl.size(); i++) {
		cout << stl.at(i) << endl;
	}


	return 0;
}



//tree<Business> d;
//int in;
//cout << "1.Tourist(sort by borderStruct.date)\n2.Employer(sort by payStruct.sum)\n3.Business(sort by lenght)\n";
//cin >> in;
//switch (in)
//{
//case 1: { tree<Tourist> a; Tourist temp; menu(a, temp); break; }
//case 2: {tree<Employer> a; Employer temp; menu(a, temp); break; }
//case 3: {
//	/*tree<Business> a; Business temp(2); menu(a, temp); break;*/

//	int in;
//	tree<Business> n;
//	int len;
//	//valueType temp;
//	while (1) {
//		print();
//		cin >> in;
//		system("cls");
//		switch (in) {
//		case 1: {
//			cout << " input lenght plz\n";
//			cin >> len;
//			Business temp(len);
//			cout << " input value plz\n";
//			temp.printShapka();
//			cin >> temp;
//			cout << temp;
//			n = temp;
//			break;
//		}
//		case 2:
//			cout << "\n";
//			n.output();
//			cout << "\n";
//			break;
//		case 3: {
//			cout << " input lenght plz\n";
//			cin >> len;
//			Business temp(len);
//			cout << " input value plz\n";
//			cin >> temp;
//			n.deleteNode(temp);
//			break;
//		}
//		case 4: {
//			cout << " input lenght plz\n";
//			cin >> len;
//			Business temp(len);
//			cout << " input value plz\n";
//			cin >> temp;
//			if (n.search(temp)) cout << "true\n";
//			else cout << "false\n";
//			break;
//		}
//		case 5:return 0;
//		default: break;

//		}
//	}




//}
//default:
//	break;
//}





	//Tourist obj("HB123", "12.09", "bel");
	//Tourist obj1("HB321", "09.09", "ukr");
	//Tourist obj2("GG456", "30.01", "rus");
	//tree<Tourist> n;
	//n = obj;
	//n = obj1;
	//n = obj2;
	//n.output();



	//int len = 2;
	//Tourist arr[2];

	//for (int i = 0; i < len; i++)
	//{
	//	//cin >> arr[i];
	//	cin >> obj;
	//	arr[i] = obj;
	//}
	//cout << "Tourist array\n";
	//arr[0].printShapka();
	//for (int i = 0; i < len; i++)
	//{
	//	cout <<  arr[i]<<endl;
	//}
	//char* str = new char[30]; int temp;
	//cout << "change passNum in array\n";
	//for (int i = 0; i < len; i++)
	//{
	//	cout << "1.Change passNum\n2.Change date\n3.change country\n";
	//	cin >> temp;
	//	
	//	if (temp == 1) {
	//		cin >> str;
	//		arr[i].setPassNum(str);
	//	}

	//	if (temp == 2) {
	//		cin >> str;
	//		arr[i].setBorDate(str);
	//	}

	//	if (temp == 2) {
	//		cin >> str;
	//		arr[i].setBorCoun(str);
	//	}
	//}

	//cout << "Tourist array\n";
	//arr[0].printShapka();
	//for (int i = 0; i < len; i++)
	//{
	//	cout << arr[i] << endl;
	//}
	//cout << endl;
	//Employer sasha("12345", "Gomel", "20.02.2020", 444444);
	//sasha.setPaySum(300);
	//sasha.setName("Sasha");
	//sasha.setSurName("Mednis");
	//sasha.setBirthDate("16.08.2002");
	//cout << sasha << " " << sasha.getName() << " " << sasha.getSurName() << " " << sasha.getBirthDate() << endl;
	////cin >> sasha;
	////cout << sasha << endl;

	//cout << endl;
	//Tourist neSasha("HB1234567","12.12.12","ukraine");
	//neSasha.setName("neSasha");
	//neSasha.setSurName("neMednis");
	//neSasha.setBirthDate("01.01.2000");
	//cout << neSasha << " " << neSasha.getName() << " " << neSasha.getSurName() << " " << neSasha.getBirthDate() << endl;
	////cin >> neSasha;
	////cout << neSasha << endl; 


	//cout << endl;
	//string s[3] = { "Poland", "Ukrain", "Pshekestan" };
	//Business oleg(s , 3);
	////cin >> oleg;
	//cout << oleg;
	////oleg.setName::Employer
	//oleg.setAddress("privet", 2);
	//oleg.setRegNum("22222");
	//oleg.setRegAd("Grondo");
	//oleg.setPayDate("12.10.2021");
	//oleg.setPaySum(300);
	//oleg.setPassNum("HB1210201");
	//oleg.setBorDate("19.12.98");
	//oleg.setBorCoun("USA");

	//cout << oleg;
