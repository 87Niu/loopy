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

    vector<int> a(n);

    for (int i = 0; i < n; i ++) cin >> a[i];

    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (a[l] != x) {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << ' ';
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }

    return 0;
}