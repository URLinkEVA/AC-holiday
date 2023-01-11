#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
int q[N];

bool check(int cnt)
{
    for (int i = 0, s = 0; i < n; i ++ )
    {
        s += q[i];
        if(s > cnt) return false;
        if(s == cnt) s = 0;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i ++ )
        {
            cin >> q[i];
            sum += q[i];
        }
        for(int i = n; i; i--)
        {
            if(sum%i==0&&check(sum/i))
            {
                cout << n - i << endl;
                break;
            }
        }
    }
    return 0;
}