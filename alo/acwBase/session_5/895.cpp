#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N], f[N];
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) {
    	f[i] = 1;
    	for (int j = 1; j < i; j ++) {
    		if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
    	}
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;

	return 0;
}