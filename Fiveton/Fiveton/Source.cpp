#include "Header.h"

Fiveton Fiveton::uniqueInstance1(15);
Fiveton Fiveton::uniqueInstance2(5);
Fiveton Fiveton::uniqueInstance3(20);
Fiveton Fiveton::uniqueInstance4(30);
Fiveton Fiveton::uniqueInstance5(100);

int Fiveton::ID = 0;
int main() {

	Fiveton& s1 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s1.getValue() << endl;



	Fiveton& s2 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s2.getValue() << endl;

	s1.setValue(11);
	cout << s1.getValue() << endl;

	Fiveton& s3 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s3.getValue() << endl;

	Fiveton& s4 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s4.getValue() << endl;

	Fiveton& s5 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s5.getValue() << endl;

	Fiveton& s6 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s6.getValue() << endl;

	Fiveton& s7 = Fiveton::getInstance();
	cout << Fiveton::getID() << ": ";
	cout << s7.getValue() << endl;

	return 0;
}