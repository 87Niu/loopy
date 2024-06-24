#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m;

const int N = 1e5 + 10;

int e[N], ne[N], idx, h[N];
int dist[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs() {

    queue<int> q;
    q.push(1);

    memset(dist, -1, sizeof dist);

    dist[1] = 0;
    while (q.size()) {

        auto t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] == -1) {
                dist[j] = dist[t] + 1;
                q.push(j);
            }
        }
    }
    cout << dist[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs();

    return 0;
}