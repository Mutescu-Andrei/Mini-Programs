#pragma once
#include<iostream>
using namespace std;
class Singleton {
private:
	static Singleton uniqueInstance1;
	static Singleton uniqueInstance2;
	int i;
	static int nrOb;
	Singleton(int x) : i(x) {
		nrOb++;
		
	}
	//void operator=(Singleton&);
	//Singleton(const Singleton&);
public:
	static Singleton& getInstance() {
		nrOb++;
		nrOb = nrOb % 2;
		if(nrOb)
			return uniqueInstance1;
		else
			return uniqueInstance2;
	}
	int getValue() {
		return i;
	}
	void setValue(int x) {
		i = x;
	}
	static int getNrOb()
	{
		return nrOb;
	}
};
