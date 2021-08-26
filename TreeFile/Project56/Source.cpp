 #include <iostream>
#include<fstream>
using namespace std;
ifstream f("cautare.txt");
 struct NOD
 { int cheie; 
 NOD *s, *d; 
 };
 typedef NOD * ABC;
 int v[100];
 void inserare(ABC &p, int c)
 {if (p != nullptr)
 if (p-> cheie == c)
 cout << " Cheie deja existenta ." << endl;
 else if (c < p-> cheie)
 inserare(p-> s, c);
 else
 inserare(p-> d, c);
 else
 {p = new (nothrow) NOD;
 if (p == nullptr)
 {cout << " Eroare la alocare ." << endl;
 exit(1);}
 p->cheie = c;
 p->s = nullptr;
 p->d = nullptr;}}

ABC creare()
 {ABC rad = nullptr;
 int c;
 cout << " Cheia noua : ";
f>> c;
cout << c;
 while (c != -1) 
 {inserare(rad, c);
 cout << " Cheia noua : ";
 f >> c;
 cout << c;
 }
 return rad;}

 void afisare(ABC p)
 {
	
	 if (p != nullptr)
 { afisare(p-> d);
 cout << p-> cheie << " ";
 afisare(p-> s);}}



 int main()
 {ABC rad = nullptr;
	 int optiune, c;
	 do
		 {cout << endl;
		 cout << " Arbore binar de cautare ." << endl;
		 cout << "1. Creare ABC prin inserari repetate ." << endl;
		 cout << "2. Afisare arbore ." << endl;
		 cout << "3. Terminare ." << endl << endl;
		
			 cout << " Optiunea conform numarului de ordine : ";
		 cin >> optiune;
		 switch (optiune)
		 {
		 case 1:
		 rad = nullptr;
		 rad = creare();
		 break;
		 case 2:
		 afisare(rad);
		 case 3:
		 break;
		 default:
		 cout << " Introduceti un numar valid de optiune (1 -> 3)!" << endl;
		 }} while (optiune != 3);
		 return 0;}
