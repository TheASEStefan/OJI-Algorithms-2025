#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e9;
vector<pair<int, int>> mat[250001]; /// matricea costurilor
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; /// coada cu prioritati pentru minim
int n, m, p, D[100001], S[100001], T[100001];

void citeste()
{
    int x, y, cost;
    fin >> n >> m >> p;
    for (int i = 1; i <= m; i ++)
    {
        fin >> x >> y >> cost;
        mat[x].push_back(make_pair(y, cost));
        mat[y].push_back(make_pair(x, cost));
    }
}

void dijkstra()
{
    for (int i = 1; i <= n; i ++)
    {
        if (i != p)
        {
            D[i] = INF;
            S[i] = 0;
            T[i] = 0;
        }
    }

    for (auto& vecin : mat[p])
    {
        int j = vecin.first;
        int cost = vecin.second;
        D[j] = cost;
        T[j] = p;
        Q.push(make_pair(D[j], j));
    }

    D[p] = 0;
    T[p] = 0;
    S[p] = 1;

    while (!(Q.empty()))
    {
        int poz = Q.top().second;
        Q.pop();
        S[poz] = 1;

        for (auto& vecin : mat[poz])
        {
            int j = vecin.first;
            int cost = vecin.second;
            if (!S[j] && D[j] > D[poz] + cost)
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
