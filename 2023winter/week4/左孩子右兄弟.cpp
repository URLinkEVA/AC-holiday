#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u)
{
    int hmax = 0, cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        hmax = max(hmax, dfs(j));
        cnt ++ ;
    }
    return hmax + cnt;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; i ++ )
    {
        int p;
        cin >> p;
        add(p, i);
    }
    cout << dfs(1) << endl;
    return 0;
}