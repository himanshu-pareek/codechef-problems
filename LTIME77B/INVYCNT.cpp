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

template < typename T >
void add_self (T & a, T b) {
    a = a + b;
}

void solve () {
    int n, k;
    scanf ("%d %d", &n, &k);
    vector < int > A (n);
    for (int & x : A) scanf ("%d", & x);
    ll answer = 0;
    vector < int > greaterCount (n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                greaterCount[i] += (A[j] > A[i]);
                add_self (answer, (ll)k);
            }
        }
        for (int j = i + 1; j < n; j++) {
            greaterCount[i] += (A[j] > A[i]);
        }
    }
    ll rep = (ll) k * (k - 1) / 2;
    for (int i = 0; i < n; i++) {
        add_self (answer, (ll) greaterCount[i] * rep);
    }
    printf ("%lld\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
