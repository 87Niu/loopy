#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1);

    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];

    while (m --) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}