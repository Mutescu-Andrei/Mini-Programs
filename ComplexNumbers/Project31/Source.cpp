#include <iostream>
#include <cmath>
using namespace std;
struct Complex {
	float re, im;
	float modul()
	{
		return sqrt(pow(re, 2) + pow(im, 2));
	}
};
Complex z[100];
void citire(Complex &z)
{
	cout << "partea reala: ";
	cin >> z.re;
	cout << "partea imaginara: ";
	cin >> z.im;
}
float ad(float a, float b)
{
	return a + b;

}

void asii(Complex a, Complex b)
{
	cout << "adunare ";
	cout << ad(a.re, b.re) << " + " << ad(a.im, b.im) << "i ";
	cout << endl;
	cout << "scadere ";
	cout << ad(a.re, -b.re) << " + " << ad(a.im, -b.im) << "i ";
	cout << endl;	
	cout << "inmultire ";
	cout << ad(a.re*b.re, a.im*b.im*(-1)) << " + " << ad(a.im*b.re, a.re*b.im) << "i ";
	cout << endl;


}
void conjugat(Complex a)
{
	cout << "conjugat ";
	cout << a.re << " + " << (-1)*a.im;

}

int main()
{
	float max;
	int n, d1, d2;
	int M;
	Complex a, b;
	cout << "Introduceti n: "; cin >> n;

	max = z[0].modul();
	M = 0;
	cout << "dati a si b "<<endl;
	citire(a);
		citire(b);
		cout << "cele n elemente " << endl;;
	for (int i = 0;i < n;i++)
	{
		citire(z[i]);
	}
	for (int i = 0;i < n;i++)
		if (z[i].modul() > max)
		{
			max = z[i].modul();
			M = i;
		}


	asii(a, b);
	cout << "Nr complex cu modul maxim: (" << z[M].re << "," << z[M].im << ") - modul: " << max << endl;
	system("pause");
	return 0;
}