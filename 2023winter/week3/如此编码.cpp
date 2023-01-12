#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 30;
int q[N];

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    q[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        q[i] = q[i-1] * x;
    }
    for (int i = 1; i <= n; i ++ )
    {
        cout << m%q[i]/q[i-1] << " ";
        m -= m % q[i];
    }
    return 0;
}