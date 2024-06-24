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

    cin >> n >> m >> q;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];

    for (int i = 0, j = m - 1; i < n && j >= 0;) {
        if (a[i] + b[j] == q) {
            cout << i << ' ' << j << endl;
            break;
        } else if (a[i] + b[j] > q) {
            j --;
        } else {
            i ++;
        }
    }

    return 0;
}