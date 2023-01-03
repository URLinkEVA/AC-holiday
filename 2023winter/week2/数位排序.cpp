#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000010;
int a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        a[i] = i;
        int s = 0;
        for (int j = i; j; j /= 10)
            s += j % 10;
        b[i] = s;
    }
    sort(a + 1, a + n + 1, [&](int x, int y) {
        if (b[x] != b[y])
            return b[x] < b[y];
        return x < y;
    });
    cout << a[m];
    return 0;
}