#include <iostream>
using namespace std;
int n, m;
float x[100],y[100],S[100],P[100];
int main()
{//Punem coeficientii in vector
	cout << "Dati gradul primului polinom ";
		cin >> n;
	cout << "Dati coeficientii ";
		for (int i = 0;i < n;i++)
			cin >> x[i];

		cout << "Dati gradul celui de al doilea polinom ";
			cin >> m;
		cout << "Dati coeficientii ";
		for (int i = 0;i < m;i++)
			cin >> y[i];

		//Suma
		int s,l;
		if (n > m)
		{
			s = n;
			for (int i = 0;i < n - m;i++)
				S[i] = x[i];
			l = n - m;
			for (int i = l;i < s;i++)
				S[i] = x[i] + y[i - l];

			for (int i = 0;i < n - m;i++)
				P[i] = x[i];
			l = n - m;
			for (int i = l;i < s;i++)
				P[i] = x[i] * y[i - l];
		}
		else
		{
			s = m;
			for (int i = 0;i < m-n;i++)
				S[i] = y[i];
			l = m-n;
			for (int i = l;i < s;i++)
				S[i] = x[i-l] + y[i];

			for (int i = 0;i < m - n;i++)
				P[i] = y[i];
			l = m - n;
			for (int i = l;i < s;i++)
				P[i] = x[i - l] * y[i];
		}
		
		
		cout << "Adunarea: ";
		for (int i = 0;i < s;i++)
		{
			cout << S[i] << "*x^" << s - i;
			if (i != s - 1)
				cout << "+";
		}
		cout << endl;
		cout << "Inmultirea: ";
		for (int i = 0;i < s;i++)
		{
			cout << P[i] << "*x^" << s - i;
			if (i != s - 1)
				cout << " * ";
		}
		cout << endl;
	system("pause");
	return 0;
}