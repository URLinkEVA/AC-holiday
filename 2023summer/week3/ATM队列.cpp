#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int n, m;
PII q[N];

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i<= n; i++)
        {
            int a;
            cin >> a;
            q[i] = {(a+m-1)/m, i};
        }
        sort(q+1, q+n+1);
        cout << "Case #" << cases << ": " ;
        for(int i = 1; i<= n; i++) cout << q[i].y << " ";
        cout << endl;
    }
    return 0;
}