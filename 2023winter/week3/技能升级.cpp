#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];
typedef long long LL;

LL times(int k)
{
    if (k == 0) return 1e18;
    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if(a[i] < k) continue;
        int l = 1, r = (a[i]+b[i]-1)/b[i];
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(a[i]-(mid-1)*b[i] >= k) l = mid;
            else r = mid-1;
        }
        res += l;
    }
    return res;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) scanf("%d%d", &a[i], &b[i]);

    int L = 1, R = 1000000;
    while (L < R)
    {
        int mid = (L + R)/2;
        if (times(mid) <= m) R = mid;
        else L = mid + 1;
    }

    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i] < L) continue;
        int l = 1, r = (a[i] + b[i] - 1) / b[i];
        while (l < r)
        {
            int mid = (l + r + 1)/2;
            if (a[i] - (mid - 1) * b[i] >= L) l = mid;
            else r = mid - 1;
        }
        res += l * 1ll * a[i] - l * 1ll * (l - 1) / 2 * b[i];
    }

    printf("%lld", res + (L - 1) * 1ll * (m - times(L)));

    return 0;
}
