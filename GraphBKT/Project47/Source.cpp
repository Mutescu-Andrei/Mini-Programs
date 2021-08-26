#include <iostream>
#include <fstream>
using namespace std;
ifstream f("graf.txt");
int n, a[100][100], x[100], m = 0;

void citire(int &n, int a[100][100])
{
	f >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			f >> a[i][j];
			if (a[i][j] == 1)
				m++;
		}
	m /= 2;
}

int valid(int k)
{
	if (k > 1)
		if (a[x[k - 1]][x[k]] != 1)
			return 0;

	for (int i = 1;i <= k - 2;i++)
		if ((x[i] == x[k - 1] && x[i + 1] == x[k]) || (x[i + 1] == x[k - 1] && x[i] == x[k]))
			return 0;
	return 1;
}

int sol(int k)
{

	if (k != m + 1)
		return 0;

	if (x[1] != x[k])
	{
		cout << x[1] << " ";
		return 0;
	}
	return 1;
}

void tipar(int k)
{
	for (int i = 1;i <= k;i++)
		cout << x[i] << " ";
	cout << endl;
}

void BKT()
{
	int k = 1;
	x[k] = 0;
	while (k)
		if (x[k] < n)
		{
			x[k] = x[k] + 1;
			if (valid(k))
				if (sol(k))
				{
					tipar(k);
					k = 0;
				}
				else
				{
					k++;
					x[k] = 0;
				}
		}
		else
			k--;
}


int main()
{
	citire(n, a);
	BKT();
	f.close();
	system("pause");
	return 0;
}