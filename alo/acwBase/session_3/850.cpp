#include <bits/stdc++.h>
using namespace std;

const int N = 150010;

int h[N], e[N], ne[N], idx, w[N];
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijstra() {

	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({0, 1});

	while (heap.size()) {
		auto t = heap.top();
		heap.pop();

		int ver = t.second, distance = t.first;
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	if (dist[n] > 0x3f3f3f3f /2) return -1;
	else return dist[n];
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

    int t = dijstra();

    cout << t << endl;

	return 0;
}