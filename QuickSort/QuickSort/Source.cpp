#include <iostream>
using namespace std;
int a[100], n;
int part(int a[100], int st, int dr)
{
	int i, j, pivot, aux;
	i = st;
	j = dr + 1;
	pivot = a[st];
	while (true)
	{
		do
		{
			i++;
		} while (i <= dr && a[i] < pivot);
		do
		{
			j--;

		} while (j >= st && a[j] > pivot);
		if (i < j)
		{
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;

		}
		else
		{
			aux = a[st];
			a[st] = a[j];
			a[j] = aux;
			return j;
		}
	}

}
void quicksort(int a[100], int st, int dr)
{
	int s;
	if (st < dr)
	{
		s = part(a, st, dr);
		quicksort(a, st, s - 1);
		quicksort(a, s + 1, dr);


	}

}
int main()
{
	cout << "n= ";
	cin >> n;
	cout << "the vector ";
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	quicksort(a, 1, n);

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}