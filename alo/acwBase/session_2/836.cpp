#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 1e5 + 10;
int p[N];


int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) p[i] = i;

    for (int i = 1; i <= m; i ++) {
        string tt;
        int a, b;
        cin >> tt >> a >> b;
        if (tt == "M") {
            a = find(a), b = find(b);
            if (a == b) continue;
            else p[b] = a;
        } else {
            a = find(a), b = find(b);
            if (a == b) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}