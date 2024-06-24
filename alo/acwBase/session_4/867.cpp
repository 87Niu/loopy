#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 100010;
int n, m;


void isPrime(int x) {
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                s ++;
                x /= i;
            }
            cout << i << ' ' << s << endl;
        }
    }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while (n --) {
        int x;
        cin >> x;
        isPrime(x);
    }
   
    return 0;
}