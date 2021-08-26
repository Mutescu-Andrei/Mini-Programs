#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
ifstream f("graf.txt");
int a[100][100], n, m, c[100][100], t[100], s[100], p[100], v1, v2, sum,v,d[100],r,l,A[100][100],ee,ss;
char o[100][30], nume[30], nume2[30], nume3[30];

void citire()
{
	int p1, p2, z;
	char x[100], y[100];
	f >> n >> m;

	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= m;j++)
		{
			c[i][j] = 32000;
			A[i][j] = 32000;
		}

	for (int i = 1;i <= n;i++)
		f >> o[i];
	for (int i = 1;i <= m;i++)
	{
		f >> x >> y >> z;
		for (int j = 1;j <= n;j++)
		{
			if (strcmp(o[j], x) == 0)
				p1 = j;
			if (strcmp(o[j], y) == 0)
				p2 = j;
		}

		c[p1][p2] = c[p2][p1] = z;
		A[p1][p2] = A[p2][p1] = z;
	}
}

void Prim()
{
	int  f;
	cout << "Localitatea din care porniti :";
	cin >> nume;
	for (int i = 1;i <= n;i++)
		if (strcmp(nume, o[i]) == 1)
			f = i;
	s[f] = 1;
	for (int k = 1;k <= n - 1;k++)
	{
		int minn = 32000;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)

				if (c[i][j] < minn && s[i] == 1 && s[j] == 0)
				{
					minn = c[i][j];
					v1 = i;
					v2 = j;
				}
		t[v2] = v1;
		s[v2] = 1;
		p[v2] = c[v1][v2];
	}
}
void dijkstra()
{

	cout << "Localitatea din care porniti :";
	cin >> nume;
	for (int i = 1;i <= n;i++)
		if (strcmp(nume, o[i]) == 0)
			v = i;
	s[v] = 1;
	for (int i = 1;i <= n;i++)
	{
		d[i] = c[v][i];
		if (i != v)
			s[i] = 0;
		if (c[v][i] != 32000 && i != v)
			t[i] = v;
	}
	for (int k1 = 1;k1 <= n - 1;k1++)
	{
		int minn = 32000, poz;
		for (int i = 1;i <= n;i++)
			if (s[i] == 0 && d[i] < minn)
			{
				minn = d[i];
				poz = i;
			}
		s[poz] = 1;

		for (int i = 1;i <= n;i++)
			if (s[i] == 0 && c[poz][i] != 32000)
				if (d[i] > d[poz] + c[poz][i])
				{
					d[i] = d[poz] + c[poz][i];
					t[i] = poz;
				}
	}
}
void Roy_Floyd()
 {
	for (int k = 0; k < n; k++)
		 for (int i = 0; i < n; i++)
		 for (int j = 0; j < n; j++)
		 if (A[i][j] > A[i][k] + A[k][j])
		 A[i][j] = A[i][k] + A[k][j];
	}

void DEI(int i, int j)
{
	 int k, find = 0;
	for (k = 0; k < n && !find; k++)
	 if (i != k && j != k && A[i][j] == A[i][k] + A[k][j])
	
		 {
	 DEI(i, k);
	 DEI(k, j);
	 find = 1;
	 }
	 if (!find)
		 cout << o[j] << " ";
	 }
void afisR(int i, int j)
 {
	 if (A[i][j] < 32000)
	 {
	 cout << " Drumul de la " << o[i]<< " la " << o[j]<< " are lungimea " << A[i][j] << endl;
	 cout << " Acesta este : " << o[i] << " ";
	 DEI(i, j);
	 }
	 else
	cout << "Nu exista drum de la " << o[i] << " la " << o[j];
	 }
void afisP()
{
	for (int i = 1;i <= n;i++)
		if (t[i] != 0)
			cout << o[t[i]] << " " << o[i] << d[i] << endl;
	cout << "Costul total: ";
	for (int i = 1;i <= n;i++)
		sum += p[i];
	cout << sum;
	cout << endl;
}
void afisB()
{
	for (int i = 1;i <= n;i++)
		if (strcmp(nume, o[i]) == 1)
			v = i;
	for (int i = 1;i <= n;i++)
		if (t[i] != 0)
			cout << o[v] << " " << o[i] <<d[i]<< endl;
	cout << sum;
	cout << endl;
}
void afisD(int i)
{
	if (t[i] != v)
	{
		afisD(t[i]);
		cout << o[i] << " ";
	}
	else
		cout << o[t[i]] << " " ;
	
}
int main()
{
	citire();
	//c) Prim();
	//c) afisP();
	dijkstra();
	/*for (int i = 1;i <n;i++)
	{
		if (strcmp(nume, o[i]) == 0)
		{
			r = i + 1;
			 l = i;
		}
		if (r == l)
			r = 0;
		r++;
		
	}*/
	cout << "Localitatea din care porniti :";
	cin >> nume2;
	cout << "Localitatea in care ajungeti :";
	cin >> nume3;
	Roy_Floyd();
	for (int i = 1;i <= n;i++)
		if (strcmp(nume2, o[i]) == 0)
			ee = i;

	for (int i = 1;i <= n;i++)
		if (strcmp(nume3, o[i]) == 0)
			ss = i;
	
	cout << ee << ss;
	afisR(ee, ss);
	cout << endl;
	/*for (int i = 1;i <= n;i++)
	{
		cout << nume << " ";
		afisD(i);
		cout << d[i] << " " << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	afisB();*/	
	system("pause");
	cout << endl;
	return 0;
}