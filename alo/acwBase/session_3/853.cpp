#include <bits/stdc++.h>

using namespace std;
const int N = 510;

int n, m, k;
int dist[N], backup[N];
struct Edge {
	int a, b, w;
}edge[10010];
void bell_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < k; i ++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < m; j ++) {
			int a = edge[j].a, b = edge[j].b, w = edge[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	edge[i] = {x, y, z};
    }

    bell_ford();
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
	return 0;
}