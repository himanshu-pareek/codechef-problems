#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template < typename T >
void min_self (T & a, T b) {
    a = min (a, b);
}

template < typename T >
void max_self (T & a, T b) {
    a = max (a, b);
}

void solve () {
    int N, K, P;
    scanf ("%d %d %d", &N, &K, &P);
    vector < int > A (N);
    for (int i = 0; i < N; i++) {
        scanf ("%d", &A[i]);
    }
    // cout << "--------------" << endl;
    // for (int x : A) {
    //     cout << x << " ";
    // }
    // cout << endl;
    K = K % 2;
    if (A.size() == 1) {
        printf ("%d\n", A[0]);
        return;
    }
    if (K) {
        int minElement = A[0], maxElement = A[0];
        for (int x : A) {
            // cout << x << " ";
            min_self (minElement, x);
            max_self (maxElement, x);
        }
        // cout << endl;
        if (P) {
            printf ("%d\n", minElement);
        } else {
            printf ("%d\n", maxElement);
        }
        return;
    }
    int minElement = A[1], maxElement = A[1];
    for (int i = 0; i < N - 2; i++) {
        min_self (minElement, max (A[i], A[i + 2]));
        max_self (maxElement, min (A[i], A[i + 2]));
    }
    min_self (minElement, A[N - 2]);
    max_self (maxElement, A[N - 2]);
    printf ("%d\n", P * minElement + (1 - P) * maxElement);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
