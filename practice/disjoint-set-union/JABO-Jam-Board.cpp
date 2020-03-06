#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e8 + 5;
const int mx = 1e4 + 10;

vector < int > parent (mx);
vector < int > scores (mx);

void createSet (int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        scores[i] = 0;
    }
}

int findSet (int u) {
    if (parent[u] != u) parent[u] = findSet (parent[u]);
    return parent[u];
}

void mergeSets (int x, int y) {
    int px = findSet (x);
    int py = findSet (y);
    if (px == py) {printf ("Invalid query!\n"); return;}
    if (scores[px] > scores[py]) parent[py] = px;
    else if (scores[px] < scores[py]) parent[px] = py;
}

void solve() {
    int n, q;
    scanf ("%d", &n);
    createSet (n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &scores[i]);
    }
    scanf ("%d", &q);
    while (q--) {
        int choice;
        scanf ("%d", &choice);
        if (choice == 0) {
            int x, y;
            scanf ("%d %d", &x, &y);
            mergeSets (x, y);
        } else {
            int x;
            scanf ("%d", &x);
            printf ("%d\n", findSet (x));
        }
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
