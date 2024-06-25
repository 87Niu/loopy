#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int N = 1e6 + 10;
int phi[N];
bool st[N];
int primes[N], cnt;
int n;
i64 olasha() {
	phi[1] = 1;
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) {
			primes[cnt ++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = true;
			phi[primes[j] * i] = phi[i] * (primes[j] - 1);

			if (i % primes[j] == 0) {
				phi[primes[j] * i] = primes[j] * phi[i];
				break;
			}
		}
	}
	i64 ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += phi[i];
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;    
	cout << olasha() << endl;
	return 0;
}