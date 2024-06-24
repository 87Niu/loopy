#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m;

const int N = 1e5 + 10;


int q[N], tt = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++) {
    	string ss;
    	int x;
    	cin >> ss;
    	if (ss == "push") {
    		cin >> x;
    		q[++ tt] = x;
    	} else if (ss == "pop") {
    		tt --;
    	} else if (ss == "empty") {
    		if (tt < 0) cout << "YES" << endl;
    		else cout << "NO" << endl;
    	} else {
    		cout<< q[tt] << endl;
    	}
    }

    return 0;
}