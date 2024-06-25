#include <bits/stdc++.h>

using namespace std;

int c[2010][2010];
const int mod = 1e9 + 7;

void init() {
	for (int i = 0; i < 2010; i ++) {
		for (int j = 0; j <= i; j ++) {
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    init();
    for (int i = 1; i <= n; i ++) {

    }

    for (int i = 0; i < n; i ++) {
    	int a, b;
    	cin >> a >> b;
    	cout << c[a][b] << endl;
    }

	return 0;
}