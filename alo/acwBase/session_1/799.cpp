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
    vector<int> a(n + 10), s(n + 10);
    for (int i = 0; i < n; i ++) cin >> a[i];

    int maxv = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        s[a[i]] ++;
        while (s[a[i]] > 1) {
            s[a[j]] --;
            j ++;
        }
        maxv = max(maxv, i - j + 1);
    }

    cout << maxv;

    return 0;
}