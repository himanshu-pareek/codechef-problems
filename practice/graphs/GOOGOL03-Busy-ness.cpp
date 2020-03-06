#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 2e5 + 10;
vector < int > parent (mx), ranks (mx);

void set_init (int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		ranks[i] = 1;
	}
}

int find (int u) {
	if (u != parent[u]) parent[u] = find (parent[u]);
	return parent[u];
}

void merge (int pu, int pv) {
	if (ranks[pv] > ranks[pu]) {
		pu ^= pv ^= pu ^= pv;
	}
	if (ranks[pu] == ranks[pv]) {
		ranks[pu]++;
	}
	parent[pv] = pu;
}

struct edge {
	int u, v, w;
	bool operator < (const edge & e) const {
		return w < e.w;
	}
};

int main() {
	int n, r, u, v, w;
	scanf ("%d %d", &n, &r);
	vector < edge > edges;
	for (int i = 0; i < r; i++) {
		scanf ("%d %d %d", &u, &v, &w);
		u--; v--;
		edges.push_back ({u, v, w});
	}
	set_init(n);
	vector < pii > busy (n);
	for (int i = 0; i < n; i++) {
		busy[i].first = i;
		busy[i].second = 0;
	}
	sort (edges.begin(), edges.end());
	for (edge e : edges) {
		int u = e.u, v = e.v, w = e.w;
		int pu = find (u);
		int pv = find (v);
		if (pu == pv) continue;
		busy[u].second++; busy[v].second++;
		merge (pu, pv);
	}
	sort (busy.begin(), busy.end(), [&] (const pii & p1, const pii & p2) {
		if (p1.second == p2.second) {
			return p1.first < p2.first;
		}
		return p1.second > p2.second;
	});
	for (pii p : busy) {
		printf ("%d\n", p.first + 1);
	}
	return 0;
}
