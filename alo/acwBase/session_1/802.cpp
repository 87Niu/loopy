#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;

vector<int> alls;
vector<pair<int, int>> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    vector<int> a(1000100), s(1000100);

    for (int i = 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (int i = 0; i < add.size(); i ++) {
        int x = find(add[i].first), c = add[i].second;
        a[x] += c;
    }

    for (int i = 1; i <= alls.size(); i ++) {
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 0; i < query.size(); i ++) {
        int l = find(query[i].first), r = find(query[i].second);

        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}