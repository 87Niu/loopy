#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x;
    cin >> x;
    double l = -10000, r = 10000;
    while (r - l >= 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%.6f\n", l);

    return 0;
}