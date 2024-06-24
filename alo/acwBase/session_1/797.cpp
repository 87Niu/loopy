#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;

void insert(vector<int> &b, int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(n + 1), b(n + 2);

    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) insert(b, i, i, a[i]);

    while (m --) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(b, l, r, c);
    }

    for (int i = 1; i <= n; i ++) b[i] += b[i - 1]; 

    for (int i = 1; i <= n; i ++) cout << b[i] << " ";

    return 0;
}