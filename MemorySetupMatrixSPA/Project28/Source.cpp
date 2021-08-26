#include <iostream>
#include <cmath>
using namespace std;


double ** citire(double &m, double &n)
{
	cout << "a= ";
	double **a;
	a = new double*[m];
	for (int i = 0; i < m; i++)
		a[i] = new double[n];
	for (int i = 0;i < m; i++)
		for (int j = 0; j < n; j++) 
		{
			cin >> a[i][j];
		}

	return a;
}


double** suma(double **a, double **b, double m, double n)
{
	double **s;
	s = new double*[m];
	for (int i = 0; i < m; i++)
		s[i] = new double[n];
	
	for (int i = 0;i < m; i++)
		for (int j = 0; j < n; j++)
			s[i][j] = a[i][j] + b[i][j];

	return s;
}

double** diferenta(double **a, double **b, double m, double n)
{
	double **d;
	d = new double*[m];
	for (int i = 0; i < m; i++)
		d[i] = new double[n];
	
	for (int i = 0;i < m; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = a[i][j] - b[i][j];

	return d;
}
//
//double** produs(double **a, double **b, double m, double n)
//{
//	double **prod;
//	prod = new double*[m];
//	for (int i = 0; i < m; i++)
//		prod[i] = new double[n];
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			for (int k = i;k <= m;k++)
//				prod[i][j] += a[i][k] * b[k][j];
//
//	return prod;
//	}

double** produs_scal(double **a, double m, double n) 
{
	double **prod;
	prod = new double*[m];
	for (int i = 0; i < m; i++)
		prod[i] = new double[n];
	double sc;
	cout << "scalar ";
	cin >> sc;
	for (int i = 0;i < m; i++)
		for (int j = 0; j < n; j++)
			prod[i][j] = sc * a[i][j];

	return prod;
}

double** transpusa(double **a, double m, double n) 
{
	double **t;
	t = new double*[m];
	for (int i = 0; i < m; i++)
		t[i] = new double[n];
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
		{
			t[i][j] = a[i][j];
		}

	return t;
}
void norme(double **a, double m, double n) 
{
	double sum1 = 0, sum2 = 0;
	double *v = new double[n];
	double *v2 = new double[n];
		float sum3 = 0, sum4 = 0;
	double n3;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			sum1 = sum1 + abs(a[i][j]);

		}
		v[i] = sum1;
		sum1 = 0;
	}
	double maxx = v[0];
	for (int i = 1;i < m;i++)
		if (v[i] > maxx)
			maxx = v[i];

	cout << maxx << " ";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum2 = sum2 + abs(a[j][i]);

		}
		v2[i] = sum2;
		sum2 = 0;
	}
	double maxx2 = v2[0];
	for (int i = 1;i < m;i++)
		if (v2[i] > maxx2)
			maxx2 = v2[i];
	cout << maxx2 << " ";
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum3 = sum3 + float(pow(a[i][j], 2));
		}
		sum4 = sum4 + sum3;
	}
	n3 = sqrt(sum4);
	cout << n3 << endl;
}

void linie(double **a, double m,double n ) 
{
	double S = 0, OK;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				S = S + abs(a[i][j]);
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{

			if (abs(a[i][i]) > S)
				OK = 1;
			else {
				OK = 0;
				break;
			}
		}
	if (OK == 1)
		cout << "DA";
	else cout << "NU";
}
void coloana(double **a, double m,double n)
{
	double S = 0, OK;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (j != i)
				S = S + abs(a[i][j]);
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) 
		{

			if (abs(a[j][j]) > S)
				OK = 1;
			else {
				OK = 0;
				break;
			}
		}
	if (OK == 1)
		cout << "DA";
	else cout << "NU";
}

void out(double **a, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}



int main()
{
	double n, m;
	cout << "m= ";
	cin >> m;
	cout << "n= ";
	cin >> n;
	double** a = citire(m, n);
	double** b = citire(m, n);

	out(suma(a, b, m, n), m, n);

	out(diferenta(a, b, m, n), m, n);


	//out(produs(a,b, m, n),m, n);

	out(produs_scal(a, m, n), m, n);



	out(transpusa(a, m, n), m, n);

	cout << "norme ";
	norme(a, m, n);

	linie(a, m,n);
	coloana(a, m,n);
	system("pause");
	return 0;
}
