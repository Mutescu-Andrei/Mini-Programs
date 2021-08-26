
#include<iostream>
#include<fstream>
using namespace std;
ifstream f("TextFile2.txt");
struct NODA
{
	int info;
	int nr;
	NODA* *FII;
};

struct NODL
{
	NODA* adr;
	NODL* next;
};

NODA* R;
NODL *vf, *sf;
void push(NODA* a)
{
	NODL* nou = new (nothrow) NODL;
	if (nou == nullptr)
	{
		cout << " Eroare de alocare " << endl;
		exit(1);
	}

	nou->adr = a;
	nou->next = vf;
	vf = nou;
}

NODA* pop()
{
	NODA* a;
	NODL* l;
	if (vf == nullptr)
		return nullptr;
	l = vf;
	vf = vf->next;
	a = l->adr;
	delete l;
	return a;

}

NODA* creare_arbore()
{
	NODA* a;
	int n;
	f >> n;
	vf = nullptr;
	for (int i = 1; i <= n; i++)
	{
		a = new(nothrow)NODA;
		if (a == nullptr)
		{
			cout << "Eroare de alocare " << endl;
			exit(1);

		}
		f >> a->info;
		f >> a->nr;
		if (a->nr == 0)
			a->FII = nullptr;
		else
		{
			a->FII = new (nothrow) NODA*[a->nr];
			if (a->FII == nullptr)
			{
				cout << "Eroare de alocare " << endl;
				exit(1);
			}
		}
		for (int j = a->nr - 1; j >= 0; j--)
			a->FII[j] = pop();
		push(a);

	}
	return pop();
}

void adaugare(NODA* a)
{
	NODL* nou;
	nou = new (nothrow) NODL;
	if (nou == nullptr)
	{
		cout << "Eroare de alocare " << endl;
		exit(1);
	}
	nou->adr = a;
	nou->next = nullptr;
	if (vf == nullptr)
	{
		vf = nou;
		sf = nou;

	}
	else
	{
		sf->next = nou;
		sf = nou;

	}
}
NODA* stergere()
{
	NODA * a;
	NODL * l;
	if (vf == nullptr) return nullptr;
	l = vf;
	vf = vf->next;
	if (vf == nullptr) sf = nullptr;
	a = l->adr;
	delete l;
	return a;
}

void parcurgere(NODA* rad)
{
	NODA* a;
	vf = nullptr;
	sf = nullptr;
	adaugare(rad);
	do
	{
		a = stergere();
		if (a != nullptr)
		{
			cout << a->info << " ";
			for (int i = 0; i < a->nr; i++)
				adaugare(a->FII[i]);

		}

	} while (a != nullptr);
	cout << endl;
}

void RSD(NODA* p)
{
	cout << p->info << " ";
	for (int i = 0; i < p->nr; i++)
		RSD(p->FII[i]);

}

void SDR(NODA* p)
{
	for (int i = 0; i < p->nr; i++)
		SDR(p->FII[i]);
	cout << p->info << " ";

}
void F(NODA* p, int maxnr, int maxinf)
{

	for (int i = 0; i < p->nr; i++)
	{
		if (p->nr >= maxnr)
		{
			maxinf = p->info;
			maxnr = p->nr;
		}

		F(p->FII[i], maxnr, maxinf);
	}

	cout << maxinf;
}

void T(NODA* p)
{
	if (p->nr == 0)
		cout << p->info << " ";

	for (int i = 0; i < p->nr; i++)
	{

		T(p->FII[i]);
	}

}


void SRD(NODA* p) {
	if (p->nr == 0) cout << p->info << " ";
	else {
		SRD(p->FII[0]);
		cout << p->info << " ";
		for (int i = 1; i < p->nr; i++)
			SRD(p->FII[i]);
	}
}


int main()
{
	int maxnr = -32000, maxinf = -32000;
	R = creare_arbore();
	parcurgere(R);
	cout << endl;
	cout << "RSD ";
	cout << endl;
	RSD(R);

	cout << endl;
	cout << "SDR ";
	cout << endl;
	SDR(R);
	cout << endl;


	cout << "SRD(inordine) ";
	cout << endl;
	SRD(R);
	cout << endl;

	cout << "pe nivele ";
	cout << endl;
	parcurgere(R);
	cout << endl;


	cout << "Nodurile cu cei mai multi fii ";
	F(R, maxnr, maxinf);
	cout << endl;
	cout << "Noduri terminale:";
	T(R);
	cout << endl;

	system("pause");

	return 0;

}
