#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;

void insert(vector<vector<int>> &b, int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)), b(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            insert(b, i, j, i, j, a[i][j]);
        }
    }

    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(b, x1, y1, x2, y2, c);
    }
   
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}