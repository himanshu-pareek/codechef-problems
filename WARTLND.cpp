#include <bits/stdc++.h>
using namespace std;

#define N 100000

typedef long long ll;

vector < pair < int, int > > edge[N + 5];
int parent[N + 5];
ll sum;
ll sizeOfCC[N + 5];
ll cnt[N + 5];

int find (int p) {
    int root = p;
    while (root != parent[root]) {
        root = parent[root];
    }
    while (p != root) {
        int q = parent[p];
        parent[p] = root;
        p = q;
    }
    return root;
}

ll nc2 (int n) {
    return (ll(n) * ll (n - 1)) / 2;
}

void merge (int u, int v) {
    int pu = find (u);
    int pv = find (v);
    if (pu == pv) return;
    sum -= nc2 (sizeOfCC[pu]);
    sum -= nc2 (sizeOfCC[pv]);
    sizeOfCC[pu] += sizeOfCC[pv];
    parent[pv] = pu;
    sum += nc2 (sizeOfCC[pu]);
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= N; i++) {
            edge[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edge[z].push_back ({x, y});
        }
        ll ans = 0;
        for (int i = N; i >= 1; i--) {
            sum = 0;
            for (int j = i; j <= N; j += i) {
                for (pair < int, int > p : edge[j]) {
                    parent[p.first] = p.first;
                    parent[p.second] = p.second;
                    sizeOfCC[p.first] = 1;
                    sizeOfCC[p.second] = 1;
                }
            }
            for (int j = i; j <= N; j += i) {
                for (pair < int, int > p : edge[j]) {
                    merge (p.first, p.second);
                }
                if (j > i) sum -= cnt[j];
            }
            cnt[i] = sum;
            ans += (cnt[i] * (ll)i);
        }
        cout << ans << endl;
    }
	return 0;
}
