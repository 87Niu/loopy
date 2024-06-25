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
    	int a, b;
    	cin >> a >> b;
    	exgcd(a, b, x, y);
    	cout << x << ' ' << y << endl;
    }

	return 0;
}