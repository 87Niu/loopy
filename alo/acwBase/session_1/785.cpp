#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


void quickSort(vector<int> &a, int l, int r) {
    if (l >= r) return;

    int x = a[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i ++; while (a[i] < x);
        do j --; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i ++) cout << a[i] << ' ';
    return 0;
}