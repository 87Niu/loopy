#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int n;
const int N = 10;
int path[N];
bool st[N];
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) cout << path[i] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }   
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dfs(0);

    return 0;
}