#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e5*2;
vector<pair<int, pair<int, int>>> edge(INF); // Muchiile Costurilor
int n, m, T[125000], Rang[125000], costMin = 0;


void citire()
{
    fin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
        int type, x, y, cost;
        fin >> type >> x >> y;
        edge[i].second.first = x;
        edge[i].second.second = y;
        edge[i].first = (type == 1) ? 0 : (fin >> cost, cost);
    }
}

void sortare()
{
    sort(edge.begin(), edge.end());
}

int root(int k)
{
    if (T[k] == k)
    {
        return k;
    }
    return T[k] = root(T[k]);
}

void rootUnion(int nodeOne, int nodeTwo)
{
    int rOne = root(nodeOne), rTwo = root(nodeTwo);
    if (rOne != rTwo)
    {
        if (Rang[rOne] > Rang[rTwo])
        {
            T[rTwo] = rOne;
        }
        else
        {
            T[rOne] = rTwo;
            if (Rang[rOne] == Rang[rTwo])
                Rang[rTwo]++;
        }
    }

}

void kruskal()
{

    for (int i = 1; i <= n; i ++)
    {
        T[i] = i;
    }

    for (auto& e : edge)
    {
        int u = e.second.first, v = e.second.second, cost = e.first;
        if (root(u) != root(v))
        {
            rootUnion(u, v);
            costMin += cost;
        }
    }

    fout << costMin << " ";
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
