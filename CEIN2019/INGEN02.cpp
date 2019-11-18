#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
    int n, x;
    scanf ("%d", &n);
    int sum = 0;
    while (n--) {
        scanf ("%d", &x);
        sum += x;
    }
    if (sum % 2) {
        printf ("NO");
    } else {
        printf ("YES");
    }
    printf ("\n");
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve ();
    }
    return 0;
}
