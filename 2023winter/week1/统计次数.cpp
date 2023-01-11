#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        for(auto c : to_string(i))
            if(c - '0' == k) cnt++;

    cout << cnt << endl;
    return 0;
}