#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool st[N];
int cnt[N];
void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}


	while (q.size()) {
		auto t = q.front();
		q.pop();

		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
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
	bool ans = spfa();
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}