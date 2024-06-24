#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int p[N];
int cnt = 0;
int n, m;
int ans = 0;

struct Edge {
	int a, b, w;
	bool operator< (const Edge& W)const {
		return w < W.w;
	}
}edge[200010];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}


int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) p[i] = i;
	for (int i = 0; i < m; i ++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[i] = {x, y, z};
	}    
	sort(edge, edge + m);
	
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i ++) {
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;
		a = find(a), b = find(b);
		if (a != b) {
			ans += w;
			p[b] = a;
			cnt ++;
		}
	}
	if (cnt < n - 1) cout << "impossible" << endl;
	else cout << ans << endl;

	return 0;
}