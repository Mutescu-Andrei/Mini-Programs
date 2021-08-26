#pragma once
#include <iostream>
using namespace std;
class Complex {
	double re, im;
public:

	Complex(double x = 0, double y = 0);
	Complex(const Complex&);
	explicit Complex(const char*);

	double modul();
	double argument();
	friend double distanta(const Complex&, const Complex&);
	double getRe();
	void setRe(double);
	double getIm();
	void setIm(double);

	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);
	int operator==(const Complex&);
	int operator!=(const Complex&);
	Complex operator-();


	Complex operator~();
	Complex& operator++();
	Complex operator++(int);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	operator double() const;
	friend ostream& operator<<(ostream& os, const Complex&);
	friend istream& operator>>(istream& is, Complex&);
};