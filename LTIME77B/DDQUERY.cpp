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

const int mx = 1e6 + 5;
vector < int > g[mx];
int parent[mx];

int dfs (int s, int t) {
    if (s == t) return 0;
    for (int u : g[s]) {
        if (u == parent[s]) continue;
        parent[u] = s;
        int temp = dfs (u, t);
        if (temp != -1) {
            return 1 + temp;
        }
    }
    return -1;
}

int dfs2 (int s, int dist, int prev, int next) {
    if (dist == 0) return s;
    for ()
}

void solve () {
    int n, q, u, v, a, da, b, db;
    scanf ("%d %d", &n, &q);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        parent[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        scanf ("%d %d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    while (q--) {
        scanf ("%d %d %d %d", &a, &da, &b, &db);
        // calculate path a -> ... ->
        int dab = dfs (b, a);
        int x = (da + dab - db) / 2;
        int y = (db + dab - da) / 2;
        if (x < 0 || y < 0) {
            printf ("-1");
            break;
        }
        int c = a;
        int prev = c;
        for (int i = 0; i < x; i++) {
            prev = c;
            c = parent[c];
        }
        int next = parent[c];
        int t = (da + db - dab) / 2;
        // for (int i = 0; i <= n; i++) {
        //     parent[i] = -1;
        // }
        int ans = dfs2 (c, t, prev, next);
    }
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
