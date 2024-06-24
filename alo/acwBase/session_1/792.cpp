#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i --) {
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}
vector<int> sub(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i ++) {
        t = a[i] - t;
        if (i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');

    if (cmp(A, B)) {
        auto c = sub(A, B);
        for (int i = 0; i < c.size(); i ++) cout << c[i];
    } else {
        cout << '-';
        auto c = sub(B, A);
        for (int i = 0; i < c.size(); i ++) cout << c[i];
    }
    

    return 0;
}