#include "Header.h"
Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}
Complex::Complex(const Complex& z) {
	re = z.re;
	im = z.im;
}


Complex::Complex(const char* str) {
	char* pos_plus = (char*)strrchr(str, '+');
	char* pos_minus = (char*)strrchr(str, '-');
	if (pos_plus == NULL) {
		re = strtod(str, &pos_minus);
		im = strtod(pos_minus, NULL);
	}
	else if (pos_minus == NULL) {
		re = strtod(str, &pos_plus);	
		im = strtod(pos_plus, NULL);
	}
	else {
		re = strtod(str, (pos_plus > pos_minus ? &pos_plus : &pos_minus));
		im = strtod(pos_plus > pos_minus ? pos_plus : pos_minus, NULL);
	}
}
double Complex::modul() {
	return sqrt(re*re + im * im);
}
double Complex::argument() {
	return atan2(im, re);
}
double distanta(const Complex& z1, const Complex& z2) {
	return sqrt((z1.re - z2.re)*(z1.re - z2.re) + (z1.im - z2.im)*(z1.im - z2.im));
}
double Complex::getRe() {
	return re;
}
void Complex::setRe(double re) {
		
		this->re = re;
}
double Complex::getIm() {
	return im;
}
void Complex::setIm(double im) {
	this->im = im;
}
Complex Complex::operator+(const Complex& c) {
	return Complex(re + c.re, im + c.im);
};
Complex Complex::operator-(const Complex& c) {
	return Complex(re - c.re, im - c.im);
};
Complex Complex::operator*(const Complex& z) {
	return Complex(re*z.re - im * z.im, re*z.im + im * z.re);
};
Complex Complex::operator/(const Complex& z) {
	double t = z.re*z.re + z.im*z.im;
	return Complex((re*z.re + im * z.im) / t,
		(im*z.re - re * z.im) / t);
};
int Complex::operator==(const Complex& z) {
	return re == z.re && im == z.im;
};
int Complex::operator!=(const Complex& z) {
	return re != z.re || im != z.im;
};
Complex Complex::operator-() {
	return Complex(-re, -im);
};
Complex Complex::operator~() {
	return Complex(re, -im);
};
Complex& Complex::operator++() {
	re++;
	return *this;
};
Complex Complex::operator++(int) {
	Complex t(*this);
	re++;
	return t;
};
Complex& Complex::operator+=(const Complex& z) {
	if (this != &z) {
		re += z.re;
		im += z.im;
	};
	return *this;
};
Complex& Complex::operator-=(const Complex& z) {
	if (this != &z) {
		re -= z.re;
		im -= z.im;
	};
	return *this;
};
Complex& Complex::operator*=(const Complex& z) {
		
		if (this != &z) {
			double t = re;
			re = re * z.re - im * z.im;
			im = t * z.im + im * z.re;
		};
	return *this;
};
Complex& Complex::operator/=(const Complex& z) {
	if (this != &z) {
		double t1 = re, t2 = z.re*z.re + z.im*z.im;
		re = (re*z.re + im * z.im) / t2;
		im = (im*z.re - t1 * z.im) / t2;
	};
	return *this;
};
Complex::operator double() const {
	return re;
};
ostream& operator<<(ostream& out, const Complex& z) {
	if (z.re == 0)out << z.im << (z.im ? "i" : "");
	else if (z.im == 0)out << z.re;
	else out << z.re << (z.im > 0 ? "+" : "") << z.im << "i";
	return out;
};
istream& operator>>(istream& in, Complex& z) {
	in >> z.re >> z.im;
	return in;
};
void main() {
	double r = 5;
	Complex c(r, 9);
	Complex z(c);

	Complex z1(5, 3);
	Complex z2(5, 1);

	cout << "z1: ";
	cout << z1;
	cout << endl;

	cout << "z2:";
	cout << z2;
	cout << endl;
	cout << endl;

	cout << "z1 + z2: ";
	cout << z1 + z2;
	cout << endl;

	cout << "z1 - z2: ";
	cout << z2 - z1;
	cout << endl;

	cout << "-z2    : ";
	cout << -z2;
	cout << endl;

	cout << "z1 * z2: ";
	cout << z1 * z2;
	cout << endl;
	
	cout << "z2 / z1: ";
	cout << z2 / z1;
	cout << endl;

	cout << "++z1   : ";
	cout << ++z1;
	cout << endl;

	cout << "~z1   : ";
	cout << ~z1;
	cout << endl;

	cout << "z1 == z2:";
	if (z1 == z2)
		cout << "da";
	else
		cout << "nu";
	cout << endl;

	cout << "Dati z3: ";
	Complex z3;
	cin >> z3;
	cout << z3;
	cout << endl;

	
	/*
	c = 5;
	z = c + (Complex)5 / z++;
	c = (Complex)"7+5.2i";
	r = (double)c;
	cin >> c;
	cout << c << endl;
	*/
	system("pause");
}