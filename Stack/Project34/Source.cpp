#include <iostream>
#include <string.h>
#ifndef STIVA_H
#define STIVA_H
using namespace std;

struct NOD;
typedef NOD* STIVA;

void error(const char[]);
void push(STIVA&, char[]);
void pop(STIVA&);
STIVA creareStiva();
STIVA creareStiva2();

struct NOD
{
	char info;
	NOD* next;
};

#endif
char cuv[256],lit;
int ok;
void error(const char msg[])
{
	cerr << "Eroare de executie. " << endl;
	cerr << msg << endl;
	cerr << "Programul se opreste." << endl;
	exit(1);

}

void push(STIVA &vf, char nInfo)
{
	STIVA nou = new (nothrow) NOD;
	if (nou == nullptr)
		error("Spatiu insuficient");
	nou->info = nInfo;
	nou->next = vf;
	vf = nou;

}

void pop(STIVA &vf,int &ok)
{
	STIVA p;
	if (vf == nullptr)
		error("Stiva vida");
	p = vf;
	if (p->info == lit)
	{
		ok = 1;
		
	}
	if (ok == 0)
		cout << "se sterge ";
	if (ok == 1)
	{
		cout << "se pastreaza ";
	}
	

	cout << p->info << " " << endl;
	vf = vf->next;
	delete p;

}
/*void pop(STIVA &vf, int &ok)
{
	STIVA p;
	if (vf == nullptr)
		error("Stiva vida");
	p = vf;
	if (p->info == lit)
	{
		ok = 1;

	}
	if (ok == 0)
		{cout << "se sterge ";
		cout << p->info << " " << endl;
	vf = vf->next;
	delete p;}
	if (ok == 1)
	{
	vf = vf->next;
	}



}
*/

STIVA creareStiva()
{
	STIVA vf = nullptr;
		int i = 0;
	while (i<=strlen(cuv))
	{if(cuv[i]>='a' && cuv[i]<='z')
		push(vf, cuv[i]);
		i++;
	}

	return vf;
}
STIVA creareStiva2()
{
	STIVA vf = nullptr;
	int i = 0;
	while (i <= strlen(cuv))
	{
		if (cuv[i] >= 'A' && cuv[i] <= 'Z')
		push(vf, cuv[i]);
		i++;
	}

	return vf;
}

int main()
{
	STIVA prim,prim2;
	
	cout << "dati cuvantul ";
	cin.get(cuv, 256);
	cout << "Dati litera ";
	cin >> lit;
	prim = creareStiva();
	prim2 = creareStiva2();
	cout << endl;
	ok = 0;
	while (prim != nullptr)
	pop(prim, ok);
	cout << endl;
	ok = 0;
	while (prim2 != nullptr)
		pop(prim2,ok);
	system("pause");
	return 0;
}