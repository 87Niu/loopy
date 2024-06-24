#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m;

const int N = 1000010;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> sta;

    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        while (!sta.empty() && sta.top() >= x) {
            sta.pop();
        }
        if (!sta.empty()) cout << sta.top() << ' ';
        else cout << "-1" << ' ';
        sta.push(x);
    }

    return 0;
}