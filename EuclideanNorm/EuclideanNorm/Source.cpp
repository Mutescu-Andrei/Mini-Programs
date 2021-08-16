#include <iostream>
#include <cmath>
using namespace std;
int s[2], neg[2], d[2], vscal[2], v1[2], v2[2], n = 2;

void read(int v1[2], int v2[2], int n)
{
	cout << "example (2 3) " << endl;
	cout << "v1= ";
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	cout << "v2= ";
	for (int i = 0; i < n; i++)
	{
		cin >> v2[i];
	}

}

void sum(int v1[], int v2[], int n)
{
	for (int i = 0; i < n; i++)
		s[i] = v1[i] + v2[i];
}

void difference(int v1[], int v2[], int n)
{
	for (int i = 0; i < n; i++)
		d[i] = v1[i] - v2[i];
}

int product(int v1[], int v2[], int n)
{
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		p = p + v1[i] * v2[i];
	}
	return p;
}

void scalar(int v1[], int vscal[], int sc, int n)
{
	for (int i = 0; i < n; i++)
		vscal[i] = sc * v1[i];
}

void negativ(int v1[], int neg[], int n)
{
	for (int i = 0; i < n; i++)
		neg[i] = -v2[i];
}

float rad(float p)
{
	float rad;
	rad = sqrt(p);
	return rad;
}


void out()
{
	int sc;
	sum(v1, v2, n);
	cout << "sum= ";
	for (int i = 0; i < 2; i++)
		cout << s[i] << " ";;
	cout << endl;

	difference(v1, v2, n);
	cout << "difference = ";
	for (int i = 0; i < 2; i++)
		cout << d[i] << " ";
	cout << endl;

	cout << "scalar: ";
	cin >> sc;

	scalar(v1, vscal, sc, n);
	cout << "scalar vector product= ";
	for (int i = 0; i < 2; i++)
		cout << vscal[i] << " ";
	cout << endl;

	negativ(v1, neg, n);
	cout << "negativization= ";
	for (int i = 0; i < 2; i++)
		cout << neg[i] << " ";
	cout << endl;




	float ps = product(v1, v2, n);

	cout << "scalar product= " << ps << " " << endl;

	cout << "euclidian norm= " << rad(ps) << endl;
}

int main()
{
	read(v1, v2, n);

	out();

	return 0;
}
