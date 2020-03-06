#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int N, K, x;
        long long S = 0LL;
        scanf ("%d %d", &N, &K);
        for (int i = 0; i < N; i++) {
            scanf ("%d", &x);
            S += x;
        }
        printf ("%lld\n", S % K);
    }
    return 0;
}

