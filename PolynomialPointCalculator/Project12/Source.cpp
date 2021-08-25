#include<iostream>
using namespace std;
int v[100], x, P,n;
int putere(int n, int x)
{
	if (n == 0)
		return 1;
	else
		return x * putere(n - 1, x);
}
int polinom(int n, int x)
{
	if (n == 0)
		return 0;
	else
		return putere(n,x)*v[n] + polinom(n - 1, x);//(x^n)*an + (x^(n-1))*a[n-1]...
}
int main()
{
	cout << "Input polynomial order  ";
	cin >> n;
	cout << "Coefficients(starting with a0): ";
		for (int i = 0;i <= n;i++)
			cin >> v[i];
		cout << "Point: ";
		cin >> x;
		P = polinom(n, x);
	P = P + v[0];//add a0
	cout << "Value = " << P<<endl;
	system("pause");
	return 0;
}