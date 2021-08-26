#include <iostream>
#include <math.h>
const int  dimMax = 50;
using namespace std;
int a[50][50], b[50][50], s[50][50], d[50][50], ps[50][50], t[50][50], prod[50][50] = {1},C[50][50], m, n, sc;

void citire(int a[dimMax][dimMax], int b[dimMax][dimMax], int &sc, int &n, int &m) {
	int i,j;
	cout << "Line n= ";
	cin >> n;
	cout << "Column m= ";
	cin >> m;
	cout << "First matrix a= ";
	for (i = 0;i < n; i++)
		for (j = 0; j < m; j++) {
		cin >> a[i][j];
	}
	cout << "Second matrix b= ";
	for (i = 0;i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	cout << "Scalar ";
	cin >> sc;

}

void Suma(int a[dimMax][dimMax], int b[dimMax][dimMax], int n, int m) {
	int i, j;
	for (i = 0;i < n; i++)
		for (j = 0; j < m; j++)
			s[i][j] = a[i][j] + b[i][j];
}

void Diferenta(int a[dimMax][dimMax], int b[dimMax][dimMax], int n, int m) {
	int i, j;
	for (i = 0;i < n; i++)
		for (j = 0; j < m; j++)
			d[i][j] = a[i][j] - b[i][j];
}

void Produsul(int a[dimMax][dimMax], int b[dimMax][dimMax], int n, int m) {
	if (n != m)
		cout << "matrici incompatibile!!!!!!"<<endl;
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				C[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < m; k++)
					C[i][j] = C[i][j] + a[i][k] * b[k][j];
	}

}


void produs_scal(int a[dimMax][dimMax], int sc, int n, int m) {
	int i, j;
	for (i = 0;i < n; i++)
		for (j = 0; j < m; j++)
			prod[i][j] = sc*a[i][j];
}

void transpusa(int a[dimMax][dimMax], int n, int m) {
	int i, j;
	for (j = 0; j < m; j++){
		for (i = 0; i < n; i++) 
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void norme(int a[dimMax][dimMax], int n, int m) {
	int Sum1 = 0, v[dimMax], Sum2 = 0, v2[dimMax], S3=0, S4=0;
	double n3;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			Sum1 = Sum1 + abs(a[i][j]);
			
		}
		v[i] = Sum1;
		Sum1 = 0;
	}
	int maxx = v[0];
	for (int i = 1;i < n;i++)
		if (v[i] > maxx)
			maxx = v[i];

	cout << maxx<<" ";
	cout << endl;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++) {
		Sum2 = Sum2 + abs(a[j][i]);

	}
	v2[i] = Sum2;
	Sum2 = 0;
}
int maxx2 = v2[0];
for (int i = 1;i < n;i++)
	if (v2[i] > maxx2)
		maxx2 = v2[i];
cout << maxx2<<" ";
cout << endl;

for (int i = 0; i < n; i++) { 
	for (int j = 0; j < m; j++) {
		S3 = S3 + pow(a[i][j], 2);
	}
	S4 = S4 + S3;
}
	n3 = sqrt(S4);
	cout << n3 << endl;
}

void strictlinie(int a[dimMax][dimMax], int n) {
	int S = 0, aux;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i != j)
				S = S + abs(a[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (abs(a[i][i]) > S)
				aux = 1;
			else {
				aux = 0;
				break;
			}
		}
	if (aux == 1)
		cout << "YES";
	else cout << "NO";
}
void strictcoloana(int a[dimMax][dimMax], int n) {
	int S = 0, aux;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (j != i)
				S = S + abs(a[i][j]);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (abs(a[j][j]) > S)
				aux = 1;
			else {
				aux = 0;
				break;
			}
		}
	if (aux == 1)
		cout << "YES";
	else cout << "NO";
}


void afisare(int sc) {
	int i, j;
	Suma(a, b, n, m);
	cout << "sum "<<endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << s[i][j]<<" ";
		cout << endl;
	}
	cout << endl;
	Diferenta(a, b, n, m);
	cout << "diff "<<endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		cout << d[i][j]<<" ";
		cout << endl;
	}
	cout << endl;
	Produsul(a, b, n, m);
	cout << "product "<<endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "scalar product "<<endl;
	produs_scal(a,sc, n, m);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << prod[i][j] << " ";
		cout << endl;
	}
	cout << "transpusa "<<endl;
	transpusa(a, n, m);
	cout << "norm "<<endl;
	norme(a, n, m);
	cout << endl;

	cout << "strictly ascending line:";
	strictlinie(a, n);
	cout << endl;
	cout << "strictly ascending column:";
	strictcoloana(a, n);
	cout << endl;

} 


int main()
{
	int sc; 
	citire(a, b, sc, n, m);
	afisare(sc);
	system("pause");
	return 0;
}
