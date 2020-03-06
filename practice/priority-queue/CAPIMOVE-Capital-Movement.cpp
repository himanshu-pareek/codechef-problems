#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mul (int a, int b) {
    return (int) (((ll) a * b) % mod);
}

void solve() {
    int n, u, v;
    scanf ("%d", &n);
    vector < int > p (n);
    for (int & x : p) scanf ("%d", & x);
    vector < int > g[n];
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &u, &v);
        u--; v--;
        g[u].push_back (v); g[v].push_back (u);
    }
    map < int, int > m;
    for (int i = 0; i < n; i++) {
        m[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int v : g[i]) {
            m.erase (p[v]);
        }
        m.erase (p[i]);
        if (m.empty()) {
            printf ("0 ");
        } else {
            printf ("%d ",1 + m.rbegin() -> second);
        }
        m[p[i]] = i;
        for (int v : g[i]) {
            m[p[v]] = v;
        }
    }
    printf ("\n");
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
