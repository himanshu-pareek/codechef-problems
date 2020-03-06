#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e9 + 10;

struct edge {
	int u, v, w;
	
	bool operator < (const edge & e) const {
		return w < e.w;
	}
};

int init (vector < int > & parent, vector < int > & rank, int n) {
	for (int i = 0; i < n; i++) {
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
	if (rank[x] == rank[y]) rank[x]++;
	parent[y] = x;
}

ll MST (vector < edge > & edges, int n) {
	sort (edges.begin(), edges.end());
	vector < int > parent (n), rank (n);
	init (parent, rank, n);
	ll ans = 0LL;
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu == pv) continue;
		ans += w;
		merge (parent, rank, pu, pv);
	}
	return ans;
}

void solve() {
	int n, m, q, u, v, w, qtype;
	cin >> n >> m >> q;
	vector < vector < int > > edge_index (n, vector < int > (n, inf));
	vector < edge > edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--; v--;
		edge_index[u][v] = edge_index[v][u] = i;
		edges.push_back ({u, v, w});
	}
	vector < edge > mst_edges;
	sort (edges.begin(), edges.end());
	vector < int > parent (n), rank (n);
	init (parent, rank, n);
	ll ans = 0LL;
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find (parent, u);
		int pv = find (parent, v);
		if (pu == pv) continue;
		mst_edges.push_back (e);
		ans += w;
		merge (parent, rank, pu, pv);
	}
	// edges.resize (0);
	// set < pair < int, int > > s;
	vector < bool > zero_weight (m, false);
	bool changed = false;
	while (q--) {
		cin >> qtype;
		//cout << "qtype - " << qtype << endl;
		if (qtype == 1) {
			cin >> u >> v;
			u--; v--;
			//cout << qtype << " " << u << " " << v << endl;
			// AssignZero (u, v)
			zero_weight[edge_index[u][v]] = true;
			changed = true;
		} else if (qtype == 2) {
			cin >> u >> v;
			u--; v--;
			//cout << qtype << " " << u << " " << v << endl;
			// AssignOriginal (u, v)
			zero_weight[edge_index[u][v]] = false;
			changed = true;
		} else {
			//MstWeight()
			if (changed) {
				vector < edge > new_edges = mst_edges;
				for (int i = 0; i < m; i++) {
					if (zero_weight[
				edges = mst_edges;
				for (pair < int, int > p : s) {
					edges.push_back ({p.first, p.second, 0});
				}
				ans = MST (edges, n);
			}
			cout << ans << endl;
			changed = false;
		}
	}
}

int main() {
	ios::sync_with_stdio (false);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

