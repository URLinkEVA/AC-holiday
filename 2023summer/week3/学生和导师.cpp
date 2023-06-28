#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N], w[N];

int main()
{
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; cases ++ )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> q[i];
        memcpy(w, q, sizeof w);
        sort(w, w + n);

        printf("Case #%d: ", cases);
        for (int i = 0; i < n; i ++ )
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (w[mid] <= 2 * q[i]) l = mid;
                else r = mid - 1;
            }

            if (w[r] == q[i]) r -- ;
            if (r < 0) printf("-1 ");
            else printf("%d ", w[r]);
        }
        puts("");
    }

    return 0;
}