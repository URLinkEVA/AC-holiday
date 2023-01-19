#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int res = 1;
    if(a == 1) return 0 & puts("1");
    if(b >= 30) return 0 & puts("-1");
    for (int i = 1; i <= b; i ++ )
    {
        if (res * 1ll * a > 1e9) return 0 & puts("-1");
        res *= a;
    }
    cout << res;
    return 0;
}