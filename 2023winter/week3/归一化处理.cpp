#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1010;
int q[N];
double a, n, d; // a平均值，n输入个数，d方差

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> q[i];
        a += q[i];
    }
    a = a/n;
    for (int i = 0; i < n; i ++ )
    {
        d += ((q[i]-a)*(q[i]-a));
    }
    d = d/n;
    for (int i = 0; i < n; i ++ )
    {
        printf("%.16f\n", (q[i] - a) / sqrt(d));
    }
    return 0;
}