#pragma once
#include <iostream>
#include <string>
using namespace std;
class numereQ {
	int a, b; // a=numarator , b=numitor

public:
	double getA();
	void setA(int);
	double getB();
	void setB(int);
	
	numereQ(int m=0, int n = 1);
	numereQ(const numereQ&);
	numereQ(double);

	numereQ operator+(const numereQ&);
	numereQ operator-(const numereQ&);
	numereQ operator*(const numereQ&);
	numereQ operator/(const numereQ&);
	
	

	numereQ& operator++();
	numereQ operator++(int);
	numereQ& operator--();
	numereQ operator--(int);

	numereQ& operator+=(const numereQ&);
	numereQ& operator-=(const numereQ&);
	numereQ& operator*=(const numereQ&);
	numereQ& operator/=(const numereQ&);

	numereQ operator-();

	 bool operator==(const numereQ&);
	 bool operator!=(const numereQ&);
	 bool operator>=(const numereQ&);
	 bool operator>(const numereQ&);
	 bool operator<=(const numereQ&);
	 bool operator<(const numereQ&);

	 void Reducere();

	friend ostream& operator<<(ostream& os, const numereQ&);
	friend istream& operator>>(istream& is, numereQ&);
};