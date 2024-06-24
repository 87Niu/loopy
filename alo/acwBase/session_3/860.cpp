#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int color[N];
int h[N], e[N * 2], ne[N * 2], idx;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int n, m;

bool dfs(int u, int c) {
	color[u] = c;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!color[j]) {
			if (!dfs(j, 3 - c))
				return false;
		} else if (color[j] == c) {
			return false;
		}
	}

	return true;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
    	int a, b;
    	cin >> a >> b;
    	add(a, b);
    	add(b, a);
    }

    bool falg = true;

    for (int i = 1; i <= n; i ++) {
    	if (!color[i]) {
    		if (!dfs(i, 1)) {
    			falg = false;
    			break;
    		}
    	}
    }

    if (falg) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}