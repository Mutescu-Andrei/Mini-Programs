#include <iostream>
using namespace std;
int x[100], m, n, a[100], v[100],S;
void citire(int &n, int &S)
{
	cout << "n= ";
	cin >> n;

	cout << "S= ";
	cin >> S;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
}
int valid(int k)
{
	return 1;
}
int suma(int k,int r)
{
	int s = 0;
	for (int i = 1;i <= k;i++)
		if(x[i]==r)
		s = s + a[i];
	return s;
}
int sol(int k)
{
	if (k != n)
		return 0;
	int ok = 0;
	for (int i = k;i >= 1;i--)
		if (suma(k,i) == S)//daca exista cel putin o submultime cu suma ceruta
			ok = 1;
	if(ok==0)
		return 0;
	return 1;
}
void tipar(int k)
{
	for (int i = 1;i <= n;i++)
	{
		cout << "{";
		for (int j = 1;j <= n;j++)
			if (x[j] == i)//partitie
				cout << a[j] << " ";//sa afiseaze interiorul in 1,1,1 poate fi {1,2,3}
		cout << "} ";
	}
	cout << endl;
}
void bkt()
{
	int k = 1;
	x[k] = 0;
	while (k != 0)
		if (x[k] <n && k <= n)
		{
			x[k] = x[k] + 1;
			if (valid(k))
				if (sol(k))
					tipar(k);
				else {
					k++;
					x[k] = 0;
				}
		}
		else k--;
}
int main()
{
	citire(n, S);
	bkt();
	system("pause");
	return 0;
}