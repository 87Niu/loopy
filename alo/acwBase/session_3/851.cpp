#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while (q.size()) {
		auto t = q.front();
		q.pop();

		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	add(x, y, z);
    }
	spfa();
    if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];

	return 0;
}