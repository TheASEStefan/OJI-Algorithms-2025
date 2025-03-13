#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e9;
vector<pair<int, int>> mat[250001]; /// matricea costurilor
queue<int> Q; /// coada pentru noduri in particular
int n, m, nodStart = 2, D[100001], InQueue[100001], S[100001];

void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        mat[x].push_back(make_pair(y, cost));
        mat[y].push_back(make_pair(x, cost));
    }
}

bool bellman_ford()
{
    for (int i = 1; i <= n; i ++)
    {
        D[i] = INF;
        S[i] = 0;
        InQueue[i] = 0;
    }
    D[nodStart] = 0;
    Q.push(nodStart);
    InQueue[nodStart] = 1;

    while (!Q.empty())
    {
        int poz = Q.front();
        Q.pop();
        S[poz]++;
      
        /// Cand avem poz repetandu-se pe sine, inseamna ca S de poz ajunge la 2, rezulta l-am vizitat de doua ori.
        /// Dar asta inseamna ca e ciclu, nu? Pentru ca nodul initial si nodul final se repeta, dar asta e un ciclu negativ.
        if (S[poz] >= n)
            return false;

        InQueue[poz] = 0;
      
        for (auto& vecin : mat[poz])
        {
            int j = vecin.first;
            int cost = vecin.second;
            if (D[j] > D[poz] + cost)
            {
                D[j] = D[poz] + cost;
                if(!InQueue[j])
                    Q.push(j);
            }
        }
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    citire();
    if (bellman_ford() == 1)
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

    fin.close();
    fout.close();

    return 0;
}
