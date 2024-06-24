#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int g[N][N];
int n, m, q;

void floyd() {

	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= m; j ++) {
    		if (i == j) g[i][j] = 0;
    		else g[i][j] = 1e9;
    	}
    }

    for (int i = 0; i < m; i ++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	g[x][y] = min(g[x][y], z);
    }
    floyd();

    while (q --) {
    	int x, y;
    	cin >> x >> y;
    	if (g[x][y] >= 1e9 / 2) cout << "impossible" << endl;
    	else cout << g[x][y] << endl;
    }
	return 0;
}