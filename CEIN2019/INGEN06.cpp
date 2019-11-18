#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        ll n;
        scanf ("%lld", &n);
        ll sum = 0;
        ll num = 1;
        while (n > 1) {
            sum += (n/2) * num;
            num <<= 1;
            n = (n/2) + (n%2);
        }
        printf ("%lld\n", sum);
    }
    return 0;
}
