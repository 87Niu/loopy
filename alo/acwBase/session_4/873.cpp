#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;
const int mod = 1e9 + 7;


i64 oula(int n) {
    vector<int> a;
    i64 ans = n;
    for (int i = 2; i <= n / i; i ++) {
        if (n % i == 0) {
            a.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) a.push_back(n);

    for (auto x : a) ans = ans / x * (x - 1) % mod;
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n --) {
        int x;
        cin >> x;
        cout << oula(x) << endl;
    }   
    return 0;
} 