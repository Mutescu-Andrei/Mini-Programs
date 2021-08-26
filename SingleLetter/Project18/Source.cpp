#include <iostream>
#include <string.h>
using namespace std;
char s1[256], s2[256];
int c1[37], c2[37],c3[37];
int main()
{
	cout << "Dati primul cuvant ";
	cin.get(s1, 256);
	cin.get();
	cout << "Dati al doilea cuvant ";
	cin.get(s2, 256);
	cin.get();
	for (int i = 0;i <= strlen(s1);i++)
		c1[int(s1[i])-97]++;//crestem valorile literelor
	for (int i = 0;i <= strlen(s2);i++)
		c2[int(s2[i])-97]++;

	for (int i = 0;i <= 36;i++)
		if (c1[i] != 0)
			cout << char('a' + i)<<" " << c1[i] << ", ";
	cout << endl;
	for (int i = 0;i <= 36;i++)
		if (c2[i] != 0)
			cout <<char( 'a' + i)<<" " << c2[i] << ", ";

	for (int i = 0;i <= 36;i++)
		c3[i] = c1[i] - c2[i];//vedem ce este doar in a
	
	int minn = -32000, iminn = -32000;
	for (int i = 0;i <= 36;i++)
		if (c3[i] > 0)
			if (minn < c3[i] || (minn == c3[i] && c1[i] <c1[iminn] ))//cea mai mica valoarea || in cazul in care este de lungime 4-3 si se mai afla ceva de 1 sa luam ce e mai mic
			{
				minn = c3[i];
				iminn = i;
			}
	cout << endl;
	cout << "Lungimea e de " << c1[iminn]<<endl;
	system("pause");
	return 0;
}	