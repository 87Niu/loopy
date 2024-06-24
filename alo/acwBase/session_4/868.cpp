#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;
int n, m;
int cnt, primes[N];
bool st[N];
int numOfS(int n) {
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i;

        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cout << numOfS(n);
   
    return 0;
}