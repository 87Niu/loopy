#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


vector<int> div(vector<int> &a, int b, int &r) {
    vector<int> c;
    
    r = 0;
    for (int i = a.size() - 1; i >= 0; i --) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());

    while (c.size() > 1 && c.back() == 0) c.pop_back();

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    int b, r;
    vector<int> A;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');


    auto c = div(A, b, r);
    
    for (int i = 0; i < c.size(); i ++) cout << c[i];

    cout << endl << r;
    return 0;
}