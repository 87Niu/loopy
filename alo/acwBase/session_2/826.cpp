#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;
const int N = 100010;

int e[N], ne[N], idx, head;

void init() {
    idx = 1;
    head = 0;
}
void addToHead(int x) {
    e[idx] = x, ne[idx] = head, head = idx ++;
}
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    cin >> n;

    for (int i = 0; i < n; i ++) {
        string tt;
        int k, x;
        cin >> tt;
        if (tt == "I") {
            cin >> k >> x;
            add(k, x);
        } else if (tt == "D") {
            cin >> k;
            if (k == 0) head = ne[head];
            else ne[k] = ne[ne[k]];
        } else {
            cin >> x;
            addToHead(x);
        }
    }

    for (int i = head; i != 0; i = ne[i]) {
        cout << e[i] << ' ';
    }
    return 0;
}