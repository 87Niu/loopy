#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 1e5 + 10;
int p[N], size_[N];


int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        size_[i] = 1;
    }

    for (int i = 1; i <= m; i ++) {
        string tt;
        int a, b;
        cin >> tt;
        if (tt == "C") {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a == b) continue;
            p[b] = a;
            size_[a] += size_[b];
        } else if (tt == "Q1") {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a == b) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            cin >> a;
            cout << size_[find(a)] << endl;
        }
    }

    return 0;
}