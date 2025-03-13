#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e9;
vector<pair<int, int>> mat[100001]; /// matricea costurilor
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; /// coada cu prioritati pentru minim
int n, m, D[100001], S[100001], T[100001];
int nodStart = 1, costTotal;

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

void prim()
{

    for (int i = 1; i <= n ; i ++)
    {
        D[i] = INF;
        T[i] = 0;
        S[i] = 0;
    }

    T[nodStart] = 0;
    D[nodStart] = 0;
    Q.push(make_pair(0, nodStart));
    while (!Q.empty())
    {
        int poz = Q.top().second;
        Q.pop();
        S[poz] = 1;
        for (auto& vecin : mat[poz])
        {
            int j = vecin.first;
            int cost = vecin.second;
            if (S[j] == 0 && D[j] > cost)
            {
                D[j] = cost;
                T[j] = poz;
                Q.push(make_pair(D[j], j));
            }
       }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    citire();
    prim();

    for (int i = 1; i <= n; i ++)
        costTotal += D[i];

    fout << costTotal << '\n';
    for (int i = 1; i <= n; i ++)
        fout << T[i] << " ";

    fin.close();
    fout.close();

    return 0;
}
