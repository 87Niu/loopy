#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL p[N], s[N];
int n, m;
char a[N];

ULL getvalue(int l, int r) {
    return s[r] - s[l - 1] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * P;
        s[i] = s[i - 1] * P + a[i];
    }

    for (int i = 0; i < m;  i ++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (getvalue(l1, r1) == getvalue(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

