#pragma once
#include<iostream>

using namespace std;



class Fiveton {
private:
	static Fiveton uniqueInstance1;
	static Fiveton uniqueInstance2;
	static Fiveton uniqueInstance3;
	static Fiveton uniqueInstance4;
	static Fiveton uniqueInstance5;
	int i;
	static int ID;
	Fiveton(int x) : i(x) {
		ID++;

	}

public:
	static Fiveton& getInstance() {
		ID++;
		ID = ID % 5;
		if (ID == 1)
			return uniqueInstance1;
		else if (ID == 2)
			return uniqueInstance2;
		else if (ID == 3)
			return uniqueInstance3;
		else if (ID == 4)
			return uniqueInstance4;
		else if (ID == 0)
			return uniqueInstance5;
	}
	int getValue() {
		return i;
	}
	void setValue(int x) {
		i = x;
	}
	static int getID()
	{
		return ID;
	}
};


