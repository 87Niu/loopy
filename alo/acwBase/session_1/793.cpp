#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


vector<int> mul(vector<int> &a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size() || t; i ++) {
        if (i < a.size()) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    int b;
    vector<int> A;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');


    auto c = mul(A, b);
    
    for (int i = 0; i < c.size(); i ++) cout << c[i];
    return 0;
}