 # include < iostream >
 # define dim 100
 using namespace std;
 int n, v[dim],v2[dim];
 void creare()
 {
	 int i, j, k, aux;
	 bool ok = false;
	 cout << " Numarul de noduri : ";
	 cin >> n;
	 if (n > dim)
		 cout << " Depasire lungime fizica a vectorului " << endl;
	 else
		 {
		 cout << " Masina noua : ";
		 cin >> v[0];
		 cout << " Timpul de parcurgere : ";
		 cin >> v2[0];
		for (j = 1; j < n; j++)
			 {
			 cout << " Cheia noua : ";
			 cin >> v[j];
			 cout << " Timpul de parcurgere : ";
			 cin >> v2[j];
			 i = j; 
			 while (i > 0 && ok == false)
							 {
				 k = (i - 1) / 2;
				 if (v[i] > v[k])
					 {
					 aux = v[i];
					 v[i] = v[k];
					 v[k] = aux;
					 aux = v2[i];
					 v2[i] = v2[k];
					 v2[k] = aux;
					 i = k; 
					 }
				 else ok = true;
				 }
			 }
	 }
 }

 void adaugare()
 {
	
		
		 int i, k, aux;
	 bool ok = false;
	 if (n == dim)
		 cout << "Nu se poate adauga nod nou , "
		 << "se depaseste lungimea fizica a vectorului ." << endl;
	 else
		 {
		 n++; 
		 cout << " Masina noua ";
		 cin >> v[n - 1];
		 cout << " Timpul scos ";
		 cin >> v2[n - 1];
		 i = n - 1;
		 while (i > 0 && ok == false)
			 {
			 k = (i - 1) / 2;
			 if (v[i] > v[k])
				 {
				 aux = v[i];
				 v[i] = v[k];
				 v[k] = aux;
				 aux = v2[i];
				 v2[i] = v2[k];
				 v2[k] = aux;
				 i = k;
				 }
			 else ok = true;
			 }
		 }
	 }

 int stergere()
 {
	 int i, j, elem = v[0],valoare=v2[0], aux;
	 bool ok = false;
	 v[0] = v[n - 1]; 
	 v2[0] = v2[n - 1];
	 n--; 
	 i = 0; 
	 while (i < n && ok == false)
		 {
		 if (2*i+1 < n)
			 {
			 j = 2*i + 1;
			 if (j + 1 < n && v[j + 1] > v[j]) j++;
				 if (v2[i] < v2[j])
				 {
				 aux = v[i];
				 v[i] = v[j];
				 v[j] = aux;
				 aux = v2[i];
				 v2[i] = v2[j];
				 v2[j] = aux;
				 i = j; }
			 else ok = true; }
	 else ok = true;}
 return elem;
 }
 void afisare()
 {
	 cout << "Ordinea masinilor este ";
	 cout << endl;
	 for (int i = 0; i < n; i++)
	 {
		 cout << v[i]<<" ";
		
	 }
 }

 void HeapSort()
{int m = n;
for (int i = n-1; i > 0; i--)
	v[i] = stergere();
	  n = m;
	 }

 int main()
 {
	int optiune;
	
	 do {cout << endl;
	 cout << " Ansamblu Heap maxim " << endl;
	 cout << "1. Creare ansamblu Heap maxim ." << endl;
	 cout << "2. Adaugare in Heap ." << endl;
	 cout << "3. Eliminare din Heap ." << endl;
	 cout << "4. Afisarea Heap ." << endl;
	 cout << "5. HeapSort ." << endl;
	 cout << "6. Terminare ." << endl;
	 cout << endl << " Introduceti optiunea conform numarului de ordine : ";
	 cin >> optiune;
	 switch (optiune)
	 {case 1:
	 creare();
	 break;
	 case 2:
	 adaugare();
	 break;
	 case 3:
	 cout << " Cheia extrasa este " << stergere() << endl;
	 break;
	 case 4:
	 afisare();
	 break;
	  case 5:
	 HeapSort();
	 break;
	 case 6:
	 break;}} while (optiune != 6);
	 return 0;
	}