#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int n;
const int N = 20;
char g[N][N];

bool col[N], dg[N], udg[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) puts(g[i]);
        puts("");
    }
    for (int i = 0; i < n; i ++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            col[i] = dg[u + i] = udg[n - u + i] = true;
            g[u][i] = 'Q';
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            g[i][j] = '.';
        }
    }
    dfs(0);

    return 0;
}