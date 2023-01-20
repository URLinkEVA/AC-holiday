#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
LL n, k, e, d, m, p, q;

int main () {
    cin >> k;
    while (k -- ) {
        cin >> n >> d >> e;
        LL m = n - e * d + 2;
        LL l = 1, r = m / 2, p, q;
        while (l <= r) {
            p = (l + r) / 2;
            q = m - p;
            if (n == p * q) break;
            else if (n < p * q) r = p - 1;
            else l = p + 1;
        }
        if (n == p * q) cout << p << ' ' << q << endl;
        else cout << "NO" << endl;
    }
    return 0;
}