#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
typedef long long LL;
int q[N],s[N];

int main()
{
    int n;
    cin >> n;
    LL cnt = 0;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    // for (int i = 0; i < n; i ++ )
    //     for (int j = i + 1; j < n; j ++ )
    //         cnt += q[i]*q[j];
    for (int i = 1; i <= n; i ++ )
        s[i] += s[i-1] + q[i-1];
    
    for (int i = 1; i <= n; i ++ )
        cnt += (LL)q[i-1] * (s[n] - s[i]); 
    
    cout << cnt;
    return 0;
}
