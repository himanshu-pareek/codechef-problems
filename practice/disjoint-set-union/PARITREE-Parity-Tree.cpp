#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e8 + 5;
const int mx = 1e4 + 10;
const int mod = 1e9 + 7;

void add_self (int & a, int b) {
    a += b;
    if (a >= mod) a-= b;
}

int mul (int a, int b) {
    return (int) (((ll) a * b) % mod);
}

int power (int a, int k) {
    int answer = 1;
    while (k >= 1) {
        if (k & 1) {
            answer = mul (answer, a);
        }
        a = mul (a, a);
        k >>= 1;
    }
    return answer;
}

void dfs (vector < vector < int > > & g, vector < int > & parent, int s, int id) {
    parent[s] = id;
    for (int v : g[s]) {
        if (parent[v] == 0) {
            dfs (g, parent, v, id);
        }
    }
}

void solve() {
    // cout << "inside solve" << endl;
    int n, q, u, v, x;
    scanf ("%d %d", &n, &q);
    vector < vector < int > > g (2 * n);
    for (int i = 0; i < n - 1; i++) {
        scanf ("%d %d", &u, &v);
    }
    while (q--) {
        scanf ("%d %d %d", &u, &v, &x);
        u--; v--;
        if (x == 0) {
            g[2 * u].push_back (2 * v);
            g[2 * v].push_back (2 * u);
            g[2 * u + 1].push_back (2 * v + 1);
            g[2 * v + 1].push_back (2 * u + 1);
        } else {
            g[2 * u].push_back (2 * v + 1);
            g[2 * v].push_back (2 * u + 1);
            g[2 * u + 1].push_back (2 * v);
            g[2 * v + 1].push_back (2 * u);
        }
    }
    int id = 0;
    vector < int > parent (2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
        if (parent[i] == 0) {
            id++;
            dfs (g, parent, i, id);
        }
    }
    for (int i = 0; i < n; i++) {
        if (parent[2 * i] == parent[2 * i + 1]) {
            printf ("0\n");
            return;
        }
    }
    printf ("%d\n", power (2, id/2 - 1));
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
