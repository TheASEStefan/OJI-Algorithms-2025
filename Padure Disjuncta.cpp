#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("nrcompconexe.in");
ofstream fout("nrcompconexe.out");

const int INF = 1e6;
int n, m, T[100001], Rang[100001];


struct poz
{
    int i , j;
}mat[500001];

/** Algoritmul Propriu zis... */
/*
*
*
*
*/

int radacina(int k)
{
    if(T[k] == 0)
        return k;
    else
    {
        int x = radacina(T[k]);
        T[k] = x;
        return x;
    }
}

void leagaRadacini(int k, int p)
{
    int rk = radacina(k), rp = radacina(p);
    if (rk != rp)
    {
        if(Rang[rk] > Rang[rp])
            T[rp] = rk;
        else
        {
            T[rk] = rp;
            if(Rang[rk] == Rang[rp])
                Rang[rp] ++;
        }
    }
}

/**
*
*
*
*
*/

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    fin >> n >> m;
    for (int i = 1 ; i <= m ; i ++)
    {
        int x, y;
        fin >> x >> y;
        mat[i].i = x;
        mat[i].j = y;
    }

    int compConexe = n;
    for (int i = 1 ; i <= m ; i ++)
    {
        int radx = radacina(mat[i].i);
        int rady = radacina(mat[i].j);
        if (radx != rady)
        {
            leagaRadacini(radx, rady);
            compConexe --;
        }
    }

    fout << compConexe << " ";

    fin.close();
    fout.close();

    return 0;
}
