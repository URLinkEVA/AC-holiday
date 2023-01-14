#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200010;
int q[N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
    {
        int t, c;
        cin >> t >> c;
        int l = t - c - k + 1, r = t - k;
        if (r <= 0 || l > 200000) continue;
        l = max(l, 1);
        r = min(r, 200000);
        q[l] ++ , q[r + 1] -- ;
    }

    for (int i = 1; i <= 200000; i ++ ) q[i] += q[i - 1];

    for (int i = 1; i <= m; i ++ )
    {
        int a;
        cin >> a;
        cout << q[a] << endl;
    }

    return 0;
}