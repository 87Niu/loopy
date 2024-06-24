#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e5 + 3;

int h[N], idx, e[N], ne[N];

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n; i ++) {
        string tt;
        int x;
        cin >> tt >> x;
        if (tt == "I") {
            insert(x);
        } else {
            if (find(x)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}