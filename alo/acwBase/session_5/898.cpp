#include <bits/stdc++.h>

using namespace std;
const int INF=0x3f3f3f3f;
const int N = 510;
int f[N][N];
int a[N][N];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	for (int j = 1; j <= i; j ++) {
    		cin >> a[i][j];
    	}
    }
    for(int i = 0; i <= n; i ++){             
        for(int j = 0; j <= i + 1; j ++){          //因为有负数，所以应该将两边也设为-INF
            f[i][j] = -INF;
        }
    }
	f[1][1] = a[1][1];
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
        }
    }

    int ans = -INF;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
	return 0;
}