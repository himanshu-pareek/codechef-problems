#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve () {
    int N;
    scanf ("%d", &N);
    int m = N / 4;
    vector < int > A (N);
    for (int & x : A) scanf ("%d", & x);
    sort (A.begin(), A.end());
    // int div = 0;
    int x[4];
    for (int div : {0, m, 2 * m, 3 * m}) {
        int next_first = m + div;
        if (A[next_first - 1] == A[next_first]) {
            printf ("-1\n"); return;
        }
        x[div/m] = A[next_first];
    }
    printf ("%d %d %d\n", x[0], x[1], x[2]);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
