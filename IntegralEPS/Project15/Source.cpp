#include <iostream>
using namespace std;
float a, b, eps, x;
float fact(float x)
{
	float f = 1;
	for (int i = 1;i <= x;i++)
		f = f * i;
	return f;
}
float euler(float aprox)
{
	float e=0;
	for (int i = 0;i <= aprox;i++)
		e=e + 1 / fact(i);
	return e;
}

float functE(float x)
{
	float e = euler(20),exp=0;
	int p = x * x;
	for (int i = 1;i <= p;i++)
	{
		exp= e * e;
		e = exp;
	}
	float me = 1 / e;
	return me ;

}
float Integrala(float a,float b,float eps)
{
	float fa, fb;
	if ((b - a) < eps)
	{
		 fa = functE(a);
		 fb = functE(b);
		return ((b - a)*(fa + fb)) / 2.0;
	}
	else
	{
		float c = (a+b) / 2.0;
		return Integrala(a, c, eps) + Integrala(c, b, eps);
	}
}
int main()
{
	cout << "eps =";
	cin >> eps;
	cout << "Integrarea in a ";
	cin >> a;
	cout << "Integrarea in b ";
	cin >> b;
	if (b < a)
	{
		int aux = a;
		a = b;
		b = aux;
	}
	cout<<"Integrala: "<<Integrala(a, b, eps)<<endl;

	system("pause");
	return 0;

}