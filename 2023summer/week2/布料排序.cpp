#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
struct Data
{
    string c;
    int d, u, idx;
}w[N];
int rnk[N];

bool cmp1(Data& a, Data& b)
{
    if(a.c != b.c) return a.c < b.c;
    return a.u < b.u;
}

bool cmp2(Data& a, Data& b)
{
    if(a.d != b.d) return a.d < b.d;
    return a.u < b.u;
}

int main()
{
    int T;
    cin >> T;
    
    for(int cases = 1; cases <= T; cases++)
    {
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            char c[11];
            int d, u;
            scanf("%s%d%d", c, &d, &u);
            w[i] = {c, d, u, i};
        }
        sort(w, w+n, cmp1);
        for (int i = 0; i < n; i ++ )
            rnk[w[i].idx] = i;
            
        sort(w, w+n, cmp2);
        int res = 0;
        for (int i = 0; i < n; i ++ )
            if(rnk[w[i].idx] == i)
                res++;
                
        printf("Case #%d: %d\n", cases, res);
    }
    return 0;
}