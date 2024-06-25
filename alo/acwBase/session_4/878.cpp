#include <bits/stdc++.h>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	} 
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n --) {
    	int x, y;
    	int a, b, m;
    	cin >> a >> b >> m;
    	int d = exgcd(a, m, x, y);
    	if (b % d == 0) {
    		cout << 1LL * x * b / d % m << endl;
    	} else {
    		cout << "impossible" << endl;
    	}
    }

	return 0;
}