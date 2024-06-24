#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;
const int N = 1e6 + 10;

int l[N], r[N], idx, e[N];

void init() {
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}
void add(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx ++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    cin >> n;

    for (int i = 0; i < n; i ++) {
        string tt;
        int k, x;
        cin >> tt;
        if (tt == "L") {
            cin >> x;
            add(0, x);
        } else if (tt == "R") {
            cin >> x;
            add(l[1], x);
        } else if (tt == "D") {
            cin >> k;
            k ++;
            r[l[k]] = r[k];
            l[r[k]] = l[k];
        } else if (tt == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        } else {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';

    
    return 0;
}