#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int n, m;
char p[N], s[N];
int ne[N];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> p[i];

  	cin >> m;
    for (int i = 1; i <= m; i ++) cin >> s[i];

    for (int i = 2, j = 0; i <= n; i ++) {
    	while (j && p[i] != p[j + 1]) j = ne[j];
    	if (p[i] == p[j + 1]) j ++;
    	ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++) {
    	while (j && s[i] != p[j + 1]) j = ne[j];
    	if (s[i] == p[j + 1]) j ++;
    	if (j == n) {
    		cout << i - n << ' ';
    		j = ne[j];
    	}
    }

	return 0;
}