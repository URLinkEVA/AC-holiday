#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
char s[N], f[30];
int cnt[30];
bool st[30];

int main()
{
    int T;
    cin >> T;
    for(int cases = 1; cases <= T; cases++)
    {
        scanf("%s%s", s, f);
        memset(st, 0, sizeof st);
        for(int i = 0; f[i]; i++)
        {
            st[f[i]-'a'] = true;
        }
        
        for(int i = 0; i < 26; i++)
        {
            int l = 0, r = 0;
            while(!st[(i+r) % 26]) r++;
            while(!st[(i-l+26)% 26 ]) l++;
            cnt[i] = min(l,r);
        }
        
        int res = 0;
        for(int i = 0; s[i]; i++)
            res += cnt[s[i] - 'a'];
            
        printf("Case #%d: %d\n", cases, res);
    }
    return 0;
}