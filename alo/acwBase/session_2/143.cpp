#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


int n, m;

const int N = 1e5 * 32 + 10;
int son[N][2];
int idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int find(int x) {
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            res = res * 2 + 1;
            p = son[p][!u];
        } else {
            res = res * 2;
            p = son[p][u];
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i ++) {
        res = max(res, find(a[i]));
    }

    cout << res << endl;


    return 0;
}