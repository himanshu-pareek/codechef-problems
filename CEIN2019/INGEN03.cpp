#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
    int x,y,a, b;
    scanf ("%d %d %d %d", &x, &y, &a, &b);
    vector < vector < ll > > dp (x + 1, vector < ll > (y + 1, 0));
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i == a && j == b) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    printf ("%lld\n", dp[x][y]);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
