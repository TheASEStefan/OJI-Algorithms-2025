#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e4;
vector<pair<int, int>> mat[50001]; /// matricea costurilor
priority_queue<pair<int, int>> Q; /// coada cu prioritati pentru minim
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
    for (int i = 1; i <= n; i ++)
    {
        if (i != nodStart)
        {
            D[i] = INF;
            S[i] = 0;
            T[i] = 0;
        }
    }

    for (int k = 0; k < mat[nodStart].size(); k ++)
    {
       int j = mat[nodStart][k].first;
       int cost = mat[nodStart][k].second;
       D[j] = cost;
       T[j] = nodStart;
       Q.push(make_pair(-cost, j));
    }
    D[nodStart] = 0;
    S[nodStart] = 1;

    while (!(Q.empty()))
    {
        int poz = Q.top().second;
        Q.pop();
        S[poz] = 1;
        for (int k = 0; k < mat[poz].size(); k ++)
        {
            int j = mat[poz][k].first;
            int cost = mat[poz][k].second;
            if (S[j] == 0 && D[j] > D[poz] + cost)
            {
                D[j] = D[poz] + cost;
                T[j] = poz;
                Q.push(make_pair(-cost, j));
            }
        }
    }

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
    citeste();
    dijkstra();

    return 0;
}
