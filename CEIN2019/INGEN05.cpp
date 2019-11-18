#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f (ll n) {
    if (n == 1) return 1;
    if (n % 2) {
        return 2 + f (n - 1);
    }
    return 2 * f (n / 2) - 1;
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        ll n;
        scanf ("%lld", &n);
        printf ("%lld\n", f (n));
    }
    return 0;
}
