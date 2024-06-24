#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;
const int INF = 0x3f3f3f3f;
int prim() {
	int ans = 0;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < n; i ++) {
		int t = -1;
		for (int j = 1; j <= n; j ++) {
			if (!st[j] && (t == -1 || dist[j] < dist[t])) {
				t = j;
			}
		}

		st[t] = true;
		if (dist[t] == INF) return INF;

		ans += dist[t];
		for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i ++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	g[x][y] = g[y][x] = min(g[x][y], z);
    }

    int ans = prim();
    if (ans == INF) cout << "impossible" << endl;
    else cout << ans << endl;

	return 0;
}