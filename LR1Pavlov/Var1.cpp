
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int strcount(const char* fname);
void myopen(ifstream& fin, const char* fname, const int n = ios_base::in);
void myopen(ofstream& fout, const char* fname, const int n = ios_base::out | ios_base::trunc);

class Customer {
	int n;
	const int t = 256;
	int K[5];
	char sep[2] = " ";
	char** T;
	char** S;
public:
	Customer();
	void show();
	void infile();
	void sortir();
	void credit();
	~Customer();
};
Customer::Customer() {
	n = strcount("Customers.txt");
	ifstream fin;
	myopen(fin, "Customers.txt");
	T = new char* [n];
	for (int i = 0; i < n; i++) {
		T[i] = new char[t];
	}
	S = new char* [n];
	for (int i = 0; i < n; i++) {
		fin.getline(T[i], t);
		S[i] = T[i];
		for (int j = 0; j < 5; j++) {
			S[i] += strcspn(S[i], sep);
			S[i] += strspn(S[i], sep);
		}
		K[i] = atoi(S[i]);
	}
	fin.close();
}
void Customer::show() {
	for (int i = 0; i < n; i++) {
		cout << T[i] << endl;
	}
}
void Customer::sortir() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*T[i] > * T[j]) {
				swap(T[i], T[j]);
				swap(K[i], K[j]);
			}
		}
	}
}
void Customer::infile() {
	ofstream fout;
	myopen(fout, "Output.txt");
	for (int i = 0; i < n; i++)
	{
		fout << T[i] << '\n';

	}
	fout.close();
}
void Customer::credit() {
	int a, b;
	cout << "Введите мин номер кредитки:  ";
	cin >> a;
	cout << "Введите макс номер кредитки:  ";
	cin >> b;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (K[i] > a&& K[i] < b) {
			cout << T[i] << endl;
		}
	}
}
Customer::~Customer() {
	for (int i = 0; i < n; i++) {
		delete[] T[i];
		
	}
	delete[] T;
	delete[] S;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "================================================" << endl
		<< "================================================" << endl;
	cout << "1 - вывод списка из файла" << endl;
	cout << "2 - вывод остсортированного списка из файла" << endl;
	cout << "3 - вывод списка по номеру кредитки из файла" << endl;
	cout << "0 - для завершения работы" << endl;
	cout << "================================================" << endl
		<< "================================================" << endl;
	cout << endl;
	Customer ab;

	while (1)
	{
		int a;
		cin >> a;
		if (a == 0) {
			ab.infile();
			break;
		}
		switch (a)
		{
		case 1:
			cout << "====================================================================" << endl;
			ab.show();
			cout << "====================================================================" << endl;
			break;
		case 2:
			ab.sortir();
			cout << "====================================================================" << endl;
			ab.show();
			cout << "====================================================================" << endl;
			break;
		case 3:
			cout << "====================================================================" << endl;
			ab.credit();
			cout << "====================================================================" << endl;
			break;
		}
	}
	
	system("pause");
	return 0;
}

int strcount(const char* fname) {
	ifstream fin; fin.open(fname, ios_base::in);
	const int nmax = 256; char t[nmax]; int n;
	for (n = 0; !fin.eof(); n++)
		fin.getline(t, nmax);
	if (!*t)n--;
	fin.close(); return n;
}
void myopen(ifstream& fin, const char* fname, const int n) {
	fin.open(fname, n);

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла " << fname << endl;
		system("pause"); exit(1);
	}
}
void myopen(ofstream& fout, const char* fname, const int n) {
	fout.open(fname, n);
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла " << fname << endl;
		system("pause"); exit(1);
	}
}
