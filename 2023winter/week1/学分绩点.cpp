#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int g[N], s[N];
int key[10] = {0, 60, 64, 68, 72, 75, 78, 82, 85, 90};
double value[10] = {0, 1.0, 1.5, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0};

double get(int x)
{
    for (int i = 9; i >= 0; i -- )
    {
        if(x >= key[i]) return value[i];
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> g[i];
    for (int i = 0; i < n; i ++ ) cin >> s[i];
    double sum = 0, cnt = 0;
    for (int i = 0; i < n; i ++ )
    {
        sum += get(s[i]) * g[i];
        cnt += g[i];
    }
    printf("%.2lf", sum/cnt); 
    return 0;
}