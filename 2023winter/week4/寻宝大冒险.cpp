#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, L, S;
const int N = 1010;
int b[N][N], x[N], y[N];
int tmp[N][N];

int main()
{
    cin >> n >> L >> S;
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &x[i], &y[i]);
    
    for (int i = S; i >= 0; i -- )
        for (int j = 0; j <= S; j ++ ) scanf("%d", &b[i][j]);
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        memset(tmp, 0, sizeof tmp);
        for (int j = 0; j < n; j ++ )
        {
            if(x[j] >= x[i] && x[j] <= x[i] + S && y[j] >= y[i] && y[j] <= y[i] + S) 
                tmp[x[j] - x[i]][y[j] - y[i]] = 1;
        }
        bool flag = true;
        for (int j = 0; j <= S; j ++ )
            for (int k = 0; k <= S; k ++ )
                if (tmp[j][k] != b[j][k] || x[i] + j > L || y[i] + k > L)
                {
                    flag = false;
                    break;
                }

        res += flag;
    }
    cout << res << endl;
    return 0;
}