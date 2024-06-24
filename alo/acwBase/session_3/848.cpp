#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

const int N = 1e5 + 10;

int e[N], ne[N], idx, h[N];
int dist[N];
int d[N];

int q[N], tt = -1, hh = 0;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topSort() {
    for (int i = 1; i <= n; i ++) {
        if (d[i] == 0) {
            q[++ tt] = i;
        }
    }
    while (hh <= tt) {
        auto t = q[hh ++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] --;
            if (d[j] == 0) {
                q[++ tt] = j;
            }
        }
    }
    if (tt != n - 1) cout << -1 << endl;
    else {
        for (int i = 0; i < n; i ++) cout << q[i] << ' '; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }
    topSort();

    return 0;
}