#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;
const int mod = 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    while (n --) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
} 