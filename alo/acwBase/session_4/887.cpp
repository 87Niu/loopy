#include <bits/stdc++.h>

using namespace std;

int n;
int qmi(int a, int k, int p) {
    int ans = 1;
    while (k) {
        if (k & 1) ans = 1LL * ans * a % p;
        k >>= 1;
        a = 1LL * a * a % p;
    }
    return ans;
}

int C(int a, int b, int p) {
	if (b > a) return 0;
	int ans = 1;
	for (int i = 1, j = a; i <= b; i ++, j --) {
		ans = 1LL * ans * j % p;
		ans = 1LL * ans * qmi(i, p - 2, p) % p;
	}
}

int lucas(int a, int b, int p) {
	if (a < p && b < p) return C(a, b, p);
	else return 1LL * C(a / p, b / p, p) * C(a % p, b % p, p) % p;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++) {
    	i64 a, b;
    	int p;
    	cin >> a >> b >> p;
    	cout << lucas(a, b, p) << endl;
    }

	return 0;
}