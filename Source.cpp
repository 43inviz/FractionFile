#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Fraction
{
	double  numerator;
	double denominator;

public:

	void setNumer(int x) {
		if (x > 0) {
			numerator = x;
		}
		else {
			cout << "numerator cant be 0\n";
			cout << "Now numerator: 1";
			numerator = 1;

		}
	}

	void setDenumer(int  y) {
		if (y > 0) {
			denominator = y;
		}
		else {
			cout << "denominator cant be 0";
			cout << "Now denominator: 1\n";
			denominator = 1;
		}

	}

	void showFract() {
		cout << numerator << endl;
		cout << "-\n";
		cout << denominator << endl;
	}

	double getNumer() {
		return numerator;
	}

	double getDenumer() {
		return denominator;
	}
	Fraction operator+(Fraction& fract) {
		Fraction res;
		res.numerator = this->numerator + fract.numerator;
		res.denominator = this->denominator + fract.denominator;

		return res;
	}

	Fraction operator-(Fraction& fract) {

		Fraction res;
		res.numerator = this->numerator - fract.numerator;
		res.denominator = this->denominator - fract.denominator;
		return res;

	}

	Fraction operator*(Fraction& fract) {
		Fraction res;
		res.numerator = this->numerator * fract.numerator;
		res.denominator = this->denominator * fract.denominator;

		return res;
	}

	Fraction operator/(Fraction& fract) {
		Fraction res;
		res.numerator = this->numerator / fract.numerator;
		res.denominator = this->denominator / fract.denominator;

		return res;
	}

	Fraction operator++(int) {//префиксная
		Fraction fract = *this;
		this->numerator++;
		this->denominator++;
		return fract;
	}

	Fraction operator++() { //постфиксная
		this->numerator;
		this->denominator;
		return *this;

	}
};



Fraction getSumFract(Fraction f1, Fraction f2) {

	Fraction res;
	res.setNumer(f1.numerator + f2.numerator);
	res.setDenumer(f1.denominator + f2.denominator);

	return res;

}

Fraction getMultFraction(Fraction f1, Fraction f2) {

	Fraction res;
	res.setNumer(f1.numerator * f2.numerator);
	res.setDenumer(f2.denominator * f2.denominator);

	return res;
}

Fraction getSubFraction(Fraction f1, Fraction f2) {

	Fraction res;
	res.setNumer(f1.numerator - f2.numerator);
	res.setDenumer(f1.denominator - f2.denominator);

	return res;
}

Fraction getDivFraction(Fraction f1, Fraction f2) {

	Fraction res;
	res.setNumer(f1.numerator / f2.numerator);
	res.setDenumer(f1.denominator / f2.denominator);

	return res;
}

void showCurrExample(Fraction f1, Fraction f2, char symb) {

	cout << endl;
	cout << "Current example: \n";
	cout << f1.numerator << "   " << f2.numerator << endl;
	cout << "-" << ' ' << symb << ' ' << "-" << endl;
	cout << f1.denominator << "   " << f2.denominator << endl;
	cout << endl;
}

void showConvertFraction(Fraction f1) {

	double res = f1.numerator / f1.denominator;
	cout << endl;
	cout << "Type of fraction in decimal: " << res << endl;

}

int main() {

	Fraction f1 = { 4,5 };
	/*Fraction f2 = f1++;
	Fraction f3 = ++f2;*/

	f1.showFract();
	cout << "^^^^\n";
	//f2.showFract();
	//cout << "^^^^\n";
	//f3.showFract();





	string fileName = "fraction.txt";


	///Запись

	ofstream fout;
	try {
		fout.open(fileName);
		fout << f1.getNumer() << "\n";


		fout << f1.getDenumer() << "\n";

	}
	catch (exception& ex) {
		cout << ex.what() << endl;

	}

	//Чтение

	Fraction fract;
	//string fileName2 = "idk.txt";

	ifstream fin;
	fin.exceptions(ifstream::failbit | ifstream::failbit);

	try {
		string numer;
		string denomi;


		fin.open(fileName);
		fin >> numer;
		fin >> denomi;



		fract.setNumer(stoi(numer));
		fract.setDenumer(stoi(denomi));
	}
	catch (exception& ex) {
		cout << ex.what() << endl;

	}

	fract.showFract();

	//int choice;

	//do {
	//	Fraction f1;
	//	Fraction f2;

	//	int x, y, x1, y1;
	//	cout << "Enter 1-st numerator: ";
	//	cin >> x;
	//	f1.setNumer(x);

	//	cout << "Enter 1-st denominator: ";
	//	cin >> y;
	//	f1.setDenumer(y);

	//	cout << "Enter 2-nf numerator: ";
	//	cin >> x1;
	//	f2.setNumer(x1);

	//	cout << "Enter 2-nd denominator: ";
	//	cin >> y1;
	//	f2.setDenumer(y1);

	//	Fraction result;

	//	cout << "1 - '+'\n2 - '-'\n3 - '*'\n4 - '/'\n0-'EXIT'\n";
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 1:
	//		showCurrExample(f1, f2, '+');
	//		result = getSumFract(f1, f2);
	//		result.showFract();
	//		showConvertFraction(result);
	//		break;
	//	case 2:
	//		showCurrExample(f1, f2, '-');
	//		result = getSubFraction(f1, f2);
	//		result.showFract();
	//		showConvertFraction(result);
	//		break;
	//	case 3:
	//		showCurrExample(f1, f2, '*');
	//		result = getMultFraction(f1, f2);
	//		result.showFract();
	//		showConvertFraction(result);
	//		break;
	//	case 4:
	//		showCurrExample(f1, f2, '/');
	//		result = getMultFraction(f1, f2);
	//		result.showFract();
	//		showConvertFraction(result);
	//		break;
	//	case 0:
	//		return 0;
	//	default:
	//		cout << "Enter wrong number";
	//		break;
	//	}


	//} while(choice != 0);



	return 0;
}