#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 747474747;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

struct edge {
	int u, v;
	ll w;
	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

void init (vector < int > & parent, vector < int > & rank, int n) {
	for (int i = 0; i  < n; i++) {
		parent[i] = i;
		rank[i] = 1;
	}
}

int find (vector < int > & parent, int u) {
	if (u != parent[u]) parent[u] = find (parent, parent[u]);
	return parent[u];
}

void merge (vector < int > & parent, vector < int > & rank, int x, int y) {
	if (rank[x] < rank[y]) {
		swap (x, y);
	}
	if (rank[x] == rank[y]) {
		rank[x]++;
	}
	parent[y] =x;
}

void solve() {
	int n, d;
	cin >> n >> d;
	vector < vector < int > > points (n, vector < int > (d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> points[i][j];
		}
	}
	vector < edge > edges;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll dist_square = 0LL;
			for (int k = 0; k < d; k++) {
				dist_square +=  (ll) (points[i][k] - points[j][k])
									* (points[i][k] - points[j][k]);
			}
			if (dist_square > 1)
				edges.push_back ({i, j, dist_square});
		}
	}
	sort (edges.begin(), edges.end());
	int ans = 1;
	vector < int > parent (n), rank (n);
	init (parent, rank, n);
	for (edge e : edges) {
		int u = e.u, v = e.v;
		int w = (e.w % mod);
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu == pv) continue;
		ans = mul (ans, w);
		merge (parent, rank, pu, pv);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

