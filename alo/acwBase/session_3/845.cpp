#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

const int N = 110;
int g[N][N];
int dist[N][N];

int bfs(string tt) {

    string end = "12345678x";

    unordered_map<string, int> dist;

    dist[tt] = 0;

    queue<string> q;

    q.push(tt);

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while (q.size()) {
        auto t = q.front();
        q.pop();

        int distance = dist[t];
        if (t == end) {
            return distance;
        }

        int c = t.find('x');
        int x = c / 3, y = c % 3;
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(t[c], t[a * 3 + b]);
                if (!dist.count(t)) {
                    dist[t] = distance + 1;
                    q.push(t);

                }
                swap(t[c], t[a * 3 + b]);
            }
        }
    }
    return -1;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char ch;
    string tt;
    for (int i = 0; i < 9; i ++) {
        cin >> ch;
        tt += ch;
    }

    cout << bfs(tt) << endl;

    return 0;
}