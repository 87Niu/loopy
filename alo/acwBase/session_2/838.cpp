#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 10;

int a[N], size_;

void down(int u) {
    int t = u;
    if (2 * u <= size_ && a[2 * u] < a[t]) t = 2 * u;
    if (2 * u + 1 <= size_ && a[2 * u + 1] < a[t]) t = 2 * u + 1;
    if (u != t) {
        swap(a[t], a[u]);
        down(t);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    size_ = n;
    for (int i = n / 2; i >= 1; i --) down(i);

    while (m --) {
        cout << a[1] << ' ';
        a[1] = a[size_ --];
        down(1);
    }

    return 0;
}