
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long n, i, ans, sum;
long long q[100010];

int main()
{
    
    cin >> n;
    for (i = 1; i <= n; i++) cin >> q[i];
    sort(q+1, q+n+1);
    for (i = 1; i <= n; i ++ )
    {
        if(sum < (n+1-i)*q[i])
        {
            sum = (n+1-i)*q[i];
            ans = q[i];
        }
    }
    cout << sum << ' ' << ans << endl;
    return 0;
}