#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 100010;
int q[N];

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    unordered_map<int, int> la;
    for (int i = 1; i <= n; i ++ )
    {
        int cur;
        cin >> cur;
        la[cur] = i;
        q[i] = max(q[i-1], la[cur ^ x]);
    }
    while (m -- )
    {
        int l, r;
        cin >> l >> r;
        if(q[r] >= l) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
