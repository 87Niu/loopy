#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

 	vector<int> a(n);

 	for (int i = 0; i < n; i ++) cin >> a[i];

 	sort(a.begin(), a.end());

 	cout << a[k - 1] << endl;
	return 0;
}