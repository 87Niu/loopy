#include <bits/stdc++.h>
using namespace std;

const int N = 520;

int g[N][N];
int dist[N];
bool st[N];
int n, m;

int dijstra() {

	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	for (int i = 1; i <= n; i ++) {
		int t = -1;
		for (int j = 1; j <= n; j ++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		for (int j = 1; j <= n; j ++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
		st[t] = true;
	}
	if (dist[n] > 0x3f3f3f3f / 2) return -1;
	else return dist[n];
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    for (int i = 0; i < m; i ++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	g[x][y] = min(g[x][y], z);
    }

    int t = dijstra();

    cout << t << endl;

	return 0;
}