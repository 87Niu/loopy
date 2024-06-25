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

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i ++) {
    	int a, p;
    	cin >> a >> p;
    	if (a % p) {
    		cout << qmi(a, p - 2, p) << endl;
    	} else {
    		cout << "impossible" << endl;
    	}
    }

	return 0;
} 