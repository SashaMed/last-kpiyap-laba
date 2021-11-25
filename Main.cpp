#include"Header.h"
#include"EmployerHeader.h"
#include"TouristHeader.h"
#include"BusinessHeader.h"
#include"Source.cpp"
#include"EmployerHeader.h"


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

int main()
{
	int n;
	
	Employer emp;
	Tourist tour;
	Business bus;
	cout << "Input variable\n";
	cin >> emp;
	//cout << "Input variable\n";
	//cin >> tour;
	//cout << "Input variable\n";
	//cin >> bus;
	cout << emp << endl;
	cout << tour << endl;
	cout << bus << endl;
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
