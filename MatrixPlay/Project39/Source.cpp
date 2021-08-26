#include <iostream>
using namespace std;
const int dim1 = 30, dim2 = 35;

int main()
{
	int m, n, mat[dim1][dim2]; // alocare statica



	
		 cout << "m: ";
		cin >> m;
		cout << "n: ";
		cin >> n;
		
		for (int i = 0; i < m; i++)
			 for (int j = 0; j < n; j++)
			 {
			cout << " mat[" << i << "," << j << "] = ";
			 cin >> mat[i][j];}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << (*(mat + i))[j] << " ";
			cout << endl;
		}


	 cout << " Varianta 2: " << endl;
	 for (int i = 0; i < m; i++)
	 {
		 int * p = mat[i], *endp = mat[i] + n - 1;
		 for (; p <= endp; p++)
			 cout << *p << " ";
		 cout << endl;
	 }

	 cout << endl;
	  cout << " Varianta 3: " << endl;
	  int(*pl)[dim2], (*endpl)[dim2];
		  pl = mat;
	 endpl = mat + m - 1; 
	  for (; pl <= endpl; pl++)
		  {
		  for (int j = 0; j < n; j++)
			 cout << (*pl)[j] << " ";
		  cout << endl;
		 }

	  cout << endl;
	  cout << " Varianta 4: " << endl;
	  
		  int* pp[dim1];
	   for (int i = 0; i < m; i++)
		  pp[i] = mat[i];
	  int ** matrice;
	   matrice = pp;
	   for (int i = 0; i < m; i++)
		   {
		  for (int j = 0; j < n; j++)
			   cout << *(*(matrice + i) + j) << " ";
		   cout << endl;
		   }
	   cout << endl;

	   system("pause");

	return 0;
}