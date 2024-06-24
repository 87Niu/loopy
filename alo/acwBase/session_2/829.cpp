#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m;

const int N = 1000010;

int q[N], tt = -1, hh = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    string s;
    int x;
    for (int i = 0; i < n; i ++) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q[++ tt] = x;
        } else if (s == "pop") {
            hh ++;
        } else if (s == "empty") {
            if (hh <= tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            cout << q[hh] << endl;
        }
    }

    return 0;
}