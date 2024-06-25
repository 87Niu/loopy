#include <bits/stdc++.h>

using namespace std;

const int N = 200010, mod = 1e9 + 7;

int n;
int fact[N], infact[N];

int qmi(int a, int k) {
	int ans = 1;
	while (k) {
		if (k & 1) ans = 1LL * ans * a % mod;
		k >>= 1;
		a = 1LL * a * a % mod;
	}
	return ans;
}

void init() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i ++) {
		fact[i] = 1LL * fact[i - 1] * i % mod;
		infact[i] = 1LL * infact[i - 1] * qmi(i, mod - 2) % mod;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> n;

    cout << 1LL * fact[2 * n] * infact[n] % mod * infact[n] * qmi(n + 1, mod - 2) % mod << endl;

	return 0;
}