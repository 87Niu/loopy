#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;

int lowbit(int x) {
    return x & -x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        int res = 0;
        while (x) {
            res ++;
            x -= lowbit(x);
        }
        cout << res << ' ';
    }

    return 0;
}