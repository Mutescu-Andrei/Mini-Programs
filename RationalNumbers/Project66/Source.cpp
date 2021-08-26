#include "Numere.h"

numereQ::numereQ(int numa, int numi)
{
	a = numa;
	b = numi;
}
numereQ::numereQ(const numereQ& x)
{
	a = x.a;
	b = x.b;

}
numereQ::numereQ(double xy)
{
	int zece = 1;
	while (xy - int(xy) > 0)
	{
		zece = zece * 10;
		xy = xy * 10;
	}
		
	this->a =int(xy);
	this->b = zece;

}
numereQ numereQ::operator+(const numereQ& x)
{
	return numereQ(a*x.b + x.a*b, b*x.b);

}
numereQ numereQ::operator-(const numereQ& x)
{
	return numereQ(a*x.b - x.a*b, b*x.b);

}
numereQ numereQ::operator*(const numereQ& x)
{
	return numereQ(a*x.a, b*x.b);


}
numereQ numereQ::operator/(const numereQ& x)
{
	return numereQ(a*x.b, b*x.a);


}

numereQ& numereQ::operator++()
{
	a += b;
	return *this;
}
numereQ numereQ::operator++(int)
{
	numereQ t(*this);
	a += b;
	return t;
}
numereQ& numereQ::operator--()
{
	a -= b;
	return *this;
}
numereQ numereQ::operator--(int)
{
	numereQ t(*this);
	a -= b;
	return t;
}
numereQ numereQ::operator-()
{
	if (b < 0)
	{
		b = -b;
		a = -a;
	}
	a = -a;
	return *this;
}
numereQ& numereQ::operator+=(const numereQ& x)
{
	if (this != &x)
	{
		a = a * x.b + x.a*b;
		b = b * x.b;

}
	return *this;
}
numereQ& numereQ::operator-=(const numereQ& x)
{
	if (this != &x)
	{
		a = a * x.b - x.a*b;
		b = b * x.b;

	}
	return *this;
}
numereQ& numereQ::operator*=(const numereQ& x)
{
	if (this != &x)
	{
		a = a * x.a;
		b = b * x.b;

	}
	return *this;
}
numereQ& numereQ::operator/=(const numereQ& x)
{
	if (this != &x)
	{
		int val=x.a;
		a = a * x.b;
		b = b *val;

	}
	return *this;
}
ostream& operator<<(ostream& out, const numereQ& x)
{
	out << x.a << "/" << x.b;
	return out;

}
istream& operator>>(istream& in,  numereQ& x)
{
	in >> x.a >> x.b;
	return in;
}
bool numereQ::operator<(const numereQ& x)
{
	double c1, c2;
	c1 = a / b;
	c2 = x.a / x.b;
	return c1<c2;

}
bool numereQ::operator>(const numereQ& x)
{

	double c1, c2;
	c1 = a / double(b);
	c2 = x.a / double(x.b);
	return c1 > c2;

}
bool numereQ::operator<=(const numereQ& x)
{

	double c1, c2;
	c1 = a / double(b);
	c2 = x.a / double(x.b);
	return c1 <= c2;

}
bool numereQ::operator>=(const numereQ& x)
{

	double c1, c2;
	c1 = a / double(b);
	c2 = x.a / double(x.b);
	return c1 >= c2;

}
bool numereQ::operator==(const numereQ& x)
{

	double c1, c2;
	c1 = a / double(b);
	c2 = x.a / double(x.b);
	
	return c1 == c2;

}
bool numereQ::operator!=(const numereQ& x)
{

	double c1, c2;
	c1 = a / double(b);
	c2 = x.a / double(x.b);
	return c1 != c2;

}
double numereQ::getA()
{
	return a;
}
double numereQ::getB()
{
	return b;
}
void numereQ::setA(int a)
{
	this->a = a;
	
}
void numereQ::setB(int b)
{
	this->b = b;
	
}
void numereQ::Reducere()
{int aQ=a,bQ=b;
	while (aQ != bQ)
	{
	if (aQ > bQ)
		aQ = aQ - bQ;
	else
		bQ = bQ - aQ;
	}
	a = a / aQ;
	b = b / bQ;
}
int main()
{
	numereQ t(7, 8), p(1, 3), r(4, 7),gol,real(5.789),cit,cit2(8.99);

	cout << "Constructor: "<< gol<<endl;
	cout << "Numar real (5.789): "<< real << endl;
	cout << "a/b + c/d: " << t <<" + "<< p <<" : "<< t + p <<endl;
	cout << "a/b - c/d: " << t << " - " << p << " : " << t - p <<endl;
	cout << "a/b * c/d: " << t << " * " << p << " : " << t * p <<endl;
	cout << "a/b / c/d: " << t << " * " << p << " : " << t / p << endl;
	
	cout << endl;
	cout << "a/b: " << r << " a/b++";
		r++;
	cout<< ": " <<r << endl;
		r--;

	
	cout << "a/b: " << r << " a/b--";
		r--;
	cout << ": " << r << endl;
		r++;
	

	cout << "a/b: " << r << " ++a/b";
		++r;
	cout << ": " << r << endl;
		r--;

		cout << "a/b: " << r << " --a/b";
		--r;
		cout << ": " << r << endl;
		r++;

	cout << "a/b: " << r << " -(a/b)";
		-r;
	cout << ": " << r << endl;
		-r;

	cout << endl;
	
	cout << "a/b += c/d: " << t << " += " << p <<endl;
		t += p;
	cout<<"a/b= "<<t<< endl;
	cout << endl;
	t -= p;
	t.Reducere();

	cout << "a/b -= c/d: " << t << " -= " << p << endl;
	t -= p;
	cout << "a/b= " << t << endl;
	cout << endl;
	t += p;
	t.Reducere();

	cout << "a/b *= c/d: " << t << " *= " << p << endl;
	t *= p;
	cout << "a/b= " << t << endl;
	cout << endl;
	t /= p;
	t.Reducere();// pentru a aduce la valoare initiala
	t.setA(7);

	

	cout << "a/b /= c/d: " << t << " /= " << p << endl;
	t /= p;
	cout << "a/b= " << t << endl;
	cout << endl;
	t *= p;
	t.Reducere();

	cout << endl;

	cout << "a/b > c/d: " << t << " > " << p<<": ";
	if (t > p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << "a/b >= c/d: " << t << " >= " << p << ": ";
	if (t >= p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << "a/b < c/d: " << t << " < " << p << ": ";
	if (t < p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << "a/b <= c/d: " << t << " <= " << p << ": ";
	if (t <= p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << "a/b == c/d: " << t << " == " << p << ": ";
	if (t == p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << "a/b <= c/d: " << t << " != " << p << ": ";
	if (t != p)
		cout << "true";
	else
		cout << "false";
	cout << endl;

	cout << endl;


	cout << "Dati numaratorul si numitorul din fractie ";
	cin >> cit;

	cout << endl;

	cout << "fractia: "<<cit;
	cout << endl;

	string aleg;
	cout << "Vreti sa reduceti fractia? da/nu " << endl;
	cin >> aleg;

	if (aleg == "da")
		cit.Reducere();
	else if (aleg == "nu")
		cout << "Vom continua cu ";

	cout << "fractia: " << cit<<endl;

	system("pause");
	return 0;
}