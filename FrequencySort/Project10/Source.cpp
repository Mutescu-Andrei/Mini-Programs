#include <iostream>
using namespace std;
int x[100], f[100], fc[100], xs[100], n, maxx,d;
int main()
{
	cout << "Dati nr de elemente ";
	cin >> n;
	cout << "Dati elementele ";
	for (int i = 0;i < n;i++)
		cin >> x[i];
	for (int i = 0;i < n;i++)
	{
		if (x[i] > maxx)
			maxx = x[i];
	}
	for (int i = 0; i < n; i++)
		f[x[i]]++;//punem frecventa fiecarui element din x[i] 
	int S = 0;
	for (int i = 0; i <= maxx; i++)
	{


		S = S + f[i];
		fc[i] = S;//frecventele cumulate

	}

	for (int i = 0; i < n; i++)
	{xs[fc[x[i]]-1] = x[i];//ne uitam la vectorul original,vedem unde corespunde pozitia elementulu x[i] in fc[i] si mutam x[i] pe pozitia fc[i]-1(ca incepe de la 0)
	fc[x[i]]--;// scadem pentru a merge pe pozitia urmatoare sa nu se aplice tot pe aceeasi
	}

	for (int i = 0; i < n; i++)
		cout << x[i] << " ";

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << xs[i] << " ";
	system("pause");
}