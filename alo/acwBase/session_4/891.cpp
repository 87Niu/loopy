#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    while (n --) {
    	int x;
    	cin >> x;
    	ans ^= x;
    }
    if (ans != 0) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}