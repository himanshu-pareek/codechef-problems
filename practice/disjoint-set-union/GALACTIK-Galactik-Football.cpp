#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e8 + 5;
const int mx = 1e5 + 10;

vector < int > parent (mx);
vector < int > ranks (mx);

void createSet (int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet (int u) {
    if (parent[u] != u) parent[u] = findSet (parent[u]);
    return parent[u];
}

void mergeSets (int x, int y) {
    int px = findSet (x);
    int py = findSet (y);
    if (px == py) return;
    if (ranks[px] > ranks[py]) parent[py] = px;
    else parent[px] = py;
    if (ranks[px] == ranks[py]) ranks[py]++;
}

int main() {
    int n, m, a, b;
    
    scanf ("%d %d", &n, &m);
    createSet (n);
    for (int i = 0; i < m; i++) {
        scanf ("%d %d", &a, &b);
        a--, b--;
        mergeSets (a, b);
    }
    vector < int > c(n);
    for (int & x : c) scanf ("%d", &x);
    vector < int > setElements[n];
    for (int i = 0; i < n; i++) {
        setElements[findSet (i)].push_back (i);
        //cout << findSet (i) << " ";
    }
    //cout << endl;
    ll sum = 0;
    int gmin = inf;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (setElements[i].size() > 0) {
            int minPositive = inf;
            for (int x : setElements[i]) {
                if (c[x] >= 0 && c[x] < minPositive) {
                    minPositive = c[x];
                }
            }
            if (minPositive == inf) {
                printf ("-1\n");
                return 0;
            } else {
                sum += minPositive;
                gmin = min (gmin, minPositive);
            }
            k++;
        }
    }
    //cout << k << " " << gmin << " " << sum << endl;
    if (k == 1) {
        printf ("%d\n", 0);
    } else {
        printf ("%lld\n", sum + (ll) (k - 2) * gmin);
    }
    return 0;
}
