#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1000010;

void getDiv(int n) {
    vector<int> a;
    for (int i = 1; i <= n / i; i ++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i != n / i) a.push_back(n / i);
        }
    }
    sort(a.begin(), a.end());
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    while (n --) {
        int x;
        cin >> x;
        getDiv(x);
    }
   
    return 0;
} 