#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

void dfs(int g[][101], int x, int n, bool visit[101])
{
    visit[x] = true;
    fout << x << " ";
    for (int j = 1; j <= n; j ++)
    {
        if (g[x][j] == 1 && !visit[j])
        {
            dfs(g, j, n, visit);
        }
    }
}


int g[101][101];
bool visit[101];
int main()
{

    int n, m, x;
    fin >> n >> m >> x;
    for (int i = 1; i <= m; i ++)
    {
        int y, z;
        fin >> y >> z;
        g[y][z] = g[z][y] = 1;
    }
    dfs(g, x, n, visit);




    return 0;
}
