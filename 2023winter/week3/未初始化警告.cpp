#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int ans = 0;
bool q[N] = {0};

int main()
{
    int k, n, x, y;
    cin >> n >> k;
    q[0] = 1;
    while(k--)
    {
        cin >> x >> y;
        if(!q[y]) ans++;
        q[x] = 1;
    }
    cout << ans << endl;
    return 0;
}