#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int n, m, q;


long long mergeSort(vector<int> &a, vector<int> &tmp, int l, int r) {

    if (l >= r) return 0;

    int mid = (l + r) >> 1;

    long long res = mergeSort(a, tmp, l, mid) + mergeSort(a, tmp, mid + 1, r);

    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k ++] = a[i ++];
        else {
            tmp[k ++] = a[j ++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k ++] = a[i ++];
    while (j <= r) tmp[k ++] = a[j ++];

    k = 0;
    for (int i = l; i <= r;) {
        a[i ++] = tmp[k ++];
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> a(n), tmp(n);

    for (int i = 0; i < n; i ++) cin >> a[i];

    cout << mergeSort(a, tmp, 0, n - 1);

    return 0;
}