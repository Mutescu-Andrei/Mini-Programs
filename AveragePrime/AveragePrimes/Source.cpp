#include <iostream>
#include <fstream>
using namespace std;
int prim(int x)
{
    int nr = 0;
    for (int d = 2; d <= x / 2; d++)
        if (x % d == 0)
            nr++;
    if (nr > 0)
        return 0;
    else return 1;

}
int main()
{
    ifstream f("program.in");

    int n, m, a[100][100] = { 0 }, nr, s;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        s = 0;
        nr = 0;
        for (int j = 1; j <= m; j++)
            if (prim(a[i][j]) == 1)
            {
                s = s + a[i][j];
                nr++;
            }
        if (nr > 0)
            cout << "Linia " << i << " - (" << float(s) << "/" << nr << "):" << float(s) / nr << endl;
        else
            cout << "Linia " << i << " - fara elemente prime " << endl;
    }

    return 0;
}
