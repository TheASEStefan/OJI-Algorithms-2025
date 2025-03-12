#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int INF = 1e6;
int n, m, int rf[101][101];

void citeste()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (i != j)
            {
                rf[i][j] = INF;
            }
        }
    }

    for (int i = 1; i <= m; i ++)
    {
        int x, y, cost;
        fin >> x >> y >> cost;
        rf[x][y] = cost;
    }
}

/** Roy Floyd Warshall, algoritm cu o complexitate 0(n^3) bazat pe programare dinamica.
Practic incearca toate nodurile unul cu altul cu un nod k intermediar. Pentru a efectua RFW, avem nevoie
ca spatiile nefolosite sa fie umplute cu INF pentru a le putea compara si adauga in MINIM.*/
void roy_floyd_warshall()
{
    for (int k = 1; k <= n; k ++)
    {
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                if (i != j && rf[i][j] > rf[i][k] + rf[k][j])
                {
                    rf[i][j] = rf[i][k] + rf[k][j];
                }
            }
        }
    }
}

void afis()
{
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (rf[i][j] != INF)
            {
                fout << rf[i][j] << " ";
            }
            else
            {
                fout << -1 << " ";
            }
        }
        fout << '\n';
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    citeste();
    roy_floyd_warshall();
    afis();

    fin.close();
    fout.close();

    return 0;
}
