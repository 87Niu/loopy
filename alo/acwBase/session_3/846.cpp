#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

const int N = 1e5 + 10;

int e[N * 2], ne[N * 2], idx, h[N];
int ans = N;
bool st[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u) {

    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);

    return sum;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;

    return 0;
}