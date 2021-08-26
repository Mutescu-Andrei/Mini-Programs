#include<iostream>
#include<fstream>
using namespace std;
ifstream f("arbore.txt");
int nr;
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
		cout<< " Eroare de alocare "<<endl;
		exit (1);
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

void latime(NODA* rad) 
{
	NODA* a;
	vf = nullptr;
	sf = nullptr;
	adaugare(rad);
	do {
		a = stergere();
		if (a != nullptr) {
			cout << a->info << " ";
			for (int i = 0; i < a->nr; i++)
				adaugare(a->FII[i]);
		}
	} while (a != nullptr);
	cout << endl;
}

void adiacenta() {
	int i, j, k,n;
	int **A;
	f >> n;
	A = new(nothrow)int*[n];
	if (A == nullptr) {
		cout << "Alocare esuata!" << endl;
		exit(1);
	}
	for (i = 0; i < n; i++) {
		A[i] = new(nothrow)int[n];
		if (A[i] == nullptr) {
			cout << "Alocare esuata!" << endl;
			exit(1);
		}
		for (j = 0; j < n; j++)
			A[i][j] = 0;
	}
	while (f >> i >> j) {
		A[i][j] = 1;
		A[j][i] = A[i][j];
	}

	for (i = 0; i < n; i++)
	{		for (j = 0; j < n; j++)
			cout << A[i][j] << " ";

	cout << endl;
	}


}
void niv(NODA* rad,int nr) 
{

	int n;
	f >> n;
	cout << "Nodul " << rad->info << " are nivelul " << nr << endl;
	nr++;
		for (int i = 0; i < rad->nr; i++)
			niv(rad->FII[i],nr);
}


int inaltime(NODA *p)
{
	if (p == NULL)
		return 0;
	else
	{
		int mx = 0;
		for (int i = 0;i <p->nr;i++)
			if (mx < inaltime(p->FII[i]))
				mx = inaltime(p->FII[i]);
		return 1 + mx;
	}
}
int main()
{
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
	cout << "Latime:";
	cout << endl;
	latime(R);
	cout << endl;
	cout << "inaltime ";
	cout << endl;

	//SRD(R);
	cout<<inaltime(R);
	//niv(R,nr);
	//adiacenta();
	cout << endl;
	
	cout << endl;
	system("pause");
	return 0;

}


