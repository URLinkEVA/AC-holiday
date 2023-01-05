#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100010;
LL a[N], s[N], q[N];

int main()
{
    LL n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    LL m;
    cin >> m;
    LL res = 0;
    LL ans = 0;
    while (m -- )
    {
        LL l, r;
        cin >> l >> r;
        q[l]++;
        q[r+1]--;
        res += s[r] - s[l-1];
    }
    for (int i = 1; i <= n; i ++ ) q[i]+=q[i-1];
    sort(a+1, a+n+1);
    sort(q+1, q+n+1);
    for (int i = 1; i <= n; i ++ ) ans+=q[i]*a[i];
    cout << ans - res;
    return 0;
}