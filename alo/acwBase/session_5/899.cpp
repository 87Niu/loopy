#include <bits/stdc++.h>

using namespace std;
const int N = 15, M = 1010;

int f[N][N];
char str[M][N];

int edit_distance(char a[], char b[]) {
	int la = strlen(a + 1), lb = strlen(b + 1);

    for (int i = 0; i <= lb; i ++ ) f[0][i] = i;
    for (int i = 0; i <= la; i ++ ) f[i][0] = i;

    for (int i = 1; i <= la; i ++ )
        for (int j = 1; j <= lb; j ++ ) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }

    return f[la][lb];

}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++) {
    	cin >> (str[i] + 1);
    }

    while (m --) {
    	char s[N];
    	int limit;
    	cin >> (s + 1) >> limit;

    	int ans = 0;
    	for (int i = 0; i < n; i ++) {
    		if (edit_distance(str[i], s) <= limit) ans ++;
    	}
    	cout << ans << endl;
    }



	return 0;
}