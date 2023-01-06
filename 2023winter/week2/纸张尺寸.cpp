#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int a = 1189, b = 841;

int main()
{
    char s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        a/=2;
        swap(a, b);
    }
    cout << a << endl << b;
    return 0;
}