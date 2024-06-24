#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

const int N = 110;
int g[N][N];
int dist[N][N];

int bfs() {

    memset(dist, -1, sizeof dist);
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    dist[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});

    while (q.size()) {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] == 0 && dist[a][b] == -1) {
                dist[a][b] = dist[t.first][t.second] + 1;
                q.push({a, b});
            }
        }
    }
    return dist[n][m];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }

    cout << bfs() << endl;
    return 0;
}