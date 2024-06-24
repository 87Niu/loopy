#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;
const int mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    unordered_map<int, int> hash;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        for (int j = 2; j <= x / j; j ++) {
            if (x % j == 0) {
                while (x % j == 0) {
                    hash[j] ++;
                    x /= j;
                }
            }
        }
        if (x > 1) hash[x] ++;
    }

    i64 res = 1;
    for (auto c : hash) {
        res = res * (c.second + 1) % mod;
    }

    cout << res << endl;
   
    return 0;
} 