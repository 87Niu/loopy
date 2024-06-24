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

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < m; i ++) cin >> b[i];

    int k = 0;
    for (int j = 0; j < m; j ++) {
        if (a[k] == b[j]) k ++;
    }
    if (k >= n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}