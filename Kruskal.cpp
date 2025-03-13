#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int n, m, S[10001], T[10001];

struct muchie
{
    int i, j, cost;

}edge[5000];

bool comp(muchie m1, muchie m2)
{
    return m1.cost < m2.cost;
}

void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        fin >> edge[i].i >> edge[i].j >> edge[i].cost;
    }
}

void sortare()
{
    sort(edge + 1, edge + m + 1, comp);
}

void kruskal()
{
    for (int i = 1 ; i <= n ; i ++)
        T[i] = i;

    int costMin = 0;
    for (int i = 1 ; i <= m; i ++)
    {
        if (T[edge[i].i] != T[edge[i].j])
        {
            S[i] = 1;
            costMin += edge[i].cost;
            int ai = T[edge[i].i];
            int aj = T[edge[i].j];
            for (int j = 1 ; j <= n ; j ++)
            {
                if (T[j] == aj)
                {
                    T[j] = ai;
                }
            }
        }
    }

    fout << costMin << '\n';
    for (int i = 1; i < m ; i ++)
    {
        if (S[i] == 1)
        {
            fout << edge[i].i << " " << edge[i].j << '\n';
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    citire();
    sortare();
    kruskal();

    fin.close();
    fout.close();

    return 0;
}
