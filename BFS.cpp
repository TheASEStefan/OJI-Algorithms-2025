#include <iostream>
#include <fstream>
#include <queue>
#define run ios::sync_with_stdio(false); fin.tie(NULL); fout.tie(NULL);
#define exit fin.close(); fout.close();

using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

void init()
{
    run;
}

void end()
{
    exit;
}

queue<int> q;

void bfs(int g[][101], int x, int n, bool visit[101])
{
    visit[x] = true;
    q.push(x);
    while (!q.empty())
    {
        int latest = q.front();
        q.pop();
        fout << latest << " ";

        for (int j = 1; j <= n; j ++)
        {
            if (g[latest][j] == 1 && !visit[j])
            {
                visit[j] = true;
                q.push(j);
            }
        }
    }
}

int g[101][101];
bool visit[101];
int main()
{

    init();
    int n, m, x;
    fin >> n >> m >> x;
    for (int i = 1; i <= m; i ++)
    {
        int y, z;
        fin >> y >> z;
        g[y][z] = g[z][y] = 1;
    }

    bfs(g, x, n, visit);
    end();



    return 0;
}
