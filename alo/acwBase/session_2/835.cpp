#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif


int n, m;

const int N = 1e5 + 10;
int son[N][26];
int idx, cnt[N];

void insert(string tt) {
    int p = 0;
    for (int i = 0; i < tt.size(); i ++) {
        int u = tt[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int find(string tt) {
    int p = 0;
    for (int i = 0; i < tt.size(); i ++) {
        int u = tt[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++) {
        string tt, ss;
        cin >> tt >> ss;
        if (tt == "I") {
            insert(ss);
        } else {
            cout << find(ss) << endl;
        }

    }

    return 0;
}