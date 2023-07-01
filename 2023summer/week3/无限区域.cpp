#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = acos(-1);

double area(double r)
{
    return r*r*PI;
}

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        double res = area(r);
        while (r)
        {
            r *= a;
            res += area(r);
            r /= b;
            res += area(r);
        }
        printf("Case #%d: %lf\n", cases, res);
    }
    return 0;
}