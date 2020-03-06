#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int N;
        scanf ("%d", &N);
        vector < int > A (N), B (N);
        for (int & x : A) scanf ("%d", &x);
        for (int & x : B) scanf ("%d", &x);
        sort (A.begin(), A.end());
        sort (B.begin(), B.end());
        long long S = 0LL;
        for (int i = 0; i < N; i++) {
            S += min (A[i], B[i]);
        }
        printf ("%lld\n", S);
    }
    return 0;
}

