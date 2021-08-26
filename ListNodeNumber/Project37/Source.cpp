#include <iostream>
#ifndef LLSI_H
#define LLSI_H
using namespace std;

struct NOD;
typedef NOD* LISTA;

void error(const char[]);
void adaugareSfarsit(LISTA&, int);
void adaugareInceput(LISTA&, int);
LISTA creareInceput();
LISTA creareSfarsit();
void stergereNod(LISTA&, int);
void afisareLista(LISTA);
int cautareInfo(LISTA, int);
void rasturnareLista(LISTA&);

struct NOD
{
	int info;
	NOD* next;
};

#endif


void error(const char msg[])
{
	cerr << "Eroare de executie. " << endl;
	cerr << msg << endl;
	cerr << "Programul se opreste." << endl;
	exit(1);

}

void adaugareSfarsit(LISTA &vf, int infon)
{
	LISTA nou = new(nothrow) NOD;
	if (nou == nullptr)
		error("Spatiu ineficient");
	nou->info = infon;
	nou->next = nullptr;
	if (vf == nullptr)
		vf = nou;
	else
	{
		LISTA p = vf;
		while (p->next != nullptr)
			p = p->next;
		p->next = nou;

	}
}
void adaugareInceput(LISTA &vf, int infon)
{
	LISTA nou = new(nothrow) NOD;
	if (nou == nullptr)
		error("Spatiu insuficient!");
	nou->info = infon;
	nou->next = vf;
	vf = nou;
}
LISTA creareInceput()
{
	int nr,n;
	LISTA vf = nullptr;
	cout << "Dati numarul de numere pe care il doriti: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> nr;
		adaugareInceput(vf, nr);
	}
	return vf;
}

void StergereNod(LISTA &vf, int infoc)
{
	LISTA  q;
	if (vf == nullptr)
	{
		cout << "Lista este vida";
		return;
	}
	if (vf->info = infoc)
	{
		q = vf;
		vf = vf->next;
		delete q;
	}

}
void afisareLISTA(LISTA vf)
{
	double man = 0, nr = 0;
	LISTA p = vf;
	if (p != nullptr)
	{
		
		while (p != nullptr)
		{

			cout << p->info<<" ";
			p = p->next;

		}
	
		cout << endl;
	}
}
int cautareInfo(LISTA vf, int infoc)
{
	int flag = 0;
	LISTA p = vf;
	while (p != nullptr)
	{
		if (p->info == infoc)
			flag++;
		p = p->next;

	}
	return flag;

}

void ElimPar(LISTA &vf, int infoc)
{
	LISTA p, q;
	if (vf == nullptr)
	{
		cout << "Lista este vida";
		return;
	}
	if (vf->info == infoc)
	{
		q = vf;
		vf = vf->next;
		delete q;
	}
	else
	{
		p = vf;
		while (p->next != nullptr)
			if (p->next->info != infoc)
			{
				p = p->next;
			}
			else
		{
			q = p->next;
			p->next = q->next;
			delete q;

		}
	}
}

int main()
{
	LISTA vf = nullptr, aux, par = nullptr, im = nullptr;
	vf = creareInceput();
	afisareLISTA(vf);
	aux = vf;
	while (vf != nullptr)
	{
		if (vf->info % 2 == 0)
			adaugareInceput(par, vf->info);
		else
			adaugareInceput(im, vf->info);
		vf = vf->next;


	}
	cout << endl;
	afisareLISTA(par);	
	cout << endl;
	afisareLISTA(im);
	int x;
	cout << endl;
	cout << "Dati nr pe care vreti sa il stergeti ";
	cin >> x;
	ElimPar(par, x);
	cout << endl;
	afisareLISTA(par);
	cout << endl;
	system("pause");
	return 0;
}
