#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 100010;
int n, m;


bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) return false;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n --) {
        int x;
        cin >> x;
        if (isPrime(x)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
   
    return 0;
}