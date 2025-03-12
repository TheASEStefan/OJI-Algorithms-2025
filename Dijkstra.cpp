#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e9;
vector<pair<int, int>> mat[50001]; /// matricea costurilor
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; /// coada cu prioritati pentru minim
int n, m, nodStart, D[50001], S[50001], T[50001];

// Graf Orientat
void citeste()
{
    int x, y, cost;
    fin >> n >> nodStart;
    while (fin >> x >> y >> cost)
    {
        m ++;
        mat[x].push_back(make_pair(y, cost));
    }
}

void dijkstra()
{
    /** Initializare si curatare din cache */
    for (int i = 1; i <= n; i ++)
    {
        if (i != nodStart)
        {
            D[i] = INF;
            S[i] = 0;
            T[i] = 0;
        }
    }

    /** Prima initializare, setare desteapta, in vectorul de tati, fiecare nod va fi legat de nodul initial
    pentru a trece prin el, costul este luat si setat in vectorul d care stocheaza costul fiecarui arc
    dintre nodul de start si nodul j curent */
    for (auto& vecin : mat[nodStart])
    {
       int j = vecin.first;
       int cost = vecin.second;
       D[j] = cost;
       T[j] = nodStart;
       Q.push(make_pair(D[j], j));
    }
    T[nodStart] = 0;
    D[nodStart] = 0;
    S[nodStart] = 1;

    while (!(Q.empty()))
    {
        int poz = Q.top().second;
        Q.pop();
        if (S[poz]) continue;
        S[poz] = 1;
        for (auto& vecin : mat[poz])
        {
            int j = vecin.first;
            int cost = vecin.second;
            if (D[j] > D[poz] + cost)
            {
                D[j] = D[poz] + cost;
                T[j] = poz;
                Q.push(make_pair(D[j], j));
            }
        }
    }

}

void afis()
{
    for (int i = 1; i <= n; i ++)
    {
        if (D[i] == INF)
        {
            fout << -1 << " ";
        }
        else
        {
            fout << D[i] << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);
    citeste();
    dijkstra();
    afis();
    fin.close();
    fout.close();

    return 0;
}
