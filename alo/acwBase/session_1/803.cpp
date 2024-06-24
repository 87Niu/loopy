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

    cin >> n;

    vector<pair<int, int>> a;

    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});
    }
    sort(a.begin(), a.end());

    int ed = -2e9;
    int res = 0;

    for (int i = 0; i < n; i ++) {
        if (ed < a[i].first) {
            res ++;
            ed = a[i].second;
        } else {
            ed = max(ed, a[i].second);
        }
    }

    cout << res << endl;

    return 0;
}