#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

vector<int> mat[100001], tmat[100001], ctc[100001];
stack<int> S;
int n, m, nrctc, viz[100001];

void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        fin >> x >> y;

        mat[x].push_back(y);
        tmat[y].push_back(x);
    }
}

void dfsInit(int nod)
{
    viz[nod] = 1;
    for (auto& vecin : mat[nod])
    {
        int dest = vecin;
        if (!viz[dest])
            dfsInit(dest);
    }
    
    S.push(nod);
}

void dfsSec(int nod)
{
    viz[nod] = 2;
    ctc[nrctc].push_back(nod);

    for (auto& vecin : tmat[nod])
    {
        int dest = vecin;
        if (viz[dest] == 1)
            dfsSec(dest);
    }
}

void kosaraju()
{
     for (int i = 1; i <= n; i ++)
     {
        if (!viz[i])
        {
            dfsInit(i);
        }
     }

    while (!S.empty())
    {
        int poz = S.top();
        S.pop();
        
        if (viz[poz] == 1)
        {
            nrctc++;
            dfsSec(poz);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    citire();
    kosaraju();

    fout << nrctc << '\n';

    return 0;
}
