#include "Header.h"
Singleton Singleton::uniqueInstance1(10);
Singleton Singleton::uniqueInstance2(5);
int Singleton::nrOb = 0;	
int main() {
	Singleton& s1 = Singleton::getInstance();
	cout << s1.getValue() << endl;
	Singleton& s2 = Singleton::getInstance();
	s2.setValue(9);
	cout << s1.getValue() << endl;
	Singleton& s3 = Singleton::getInstance();
	cout << s1.getValue() << endl;
	Singleton& s4 = Singleton::getInstance();
	cout << s4.getValue() << endl;


	cout << Singleton::getNrOb() << endl;
	return 0;
}