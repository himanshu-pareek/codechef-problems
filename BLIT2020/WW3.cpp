#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
	vector < int > parent;
	vector < int > size;
	
	DSU (int n) {
		parent.resize (n);
		size.resize (n);
	}
	
	void set (int i) {
		parent[i] = i;
		size[i] = 1;
	}
	
	int find (int i) {
		if (i != parent[i]) parent[i] = find (parent[i]);
		return parent[i];
	}
	
	ll merge (int u, int v) {
		u = find (u);
		v = find (v);
		if (u == v) return 0LL;
		ll toReturn = 1LL * size[u] * size[v];
		if (size[u] < size[v]) {
			swap (u, v);
		}
		parent[v] = u;
		size[u] += size[v];
		return toReturn;
	}
};

struct edge {
	int u, v, w, index;
	
	//edge (int u, int v, int w, int index) {
		//this -> u = u;
		//this -> v = v;
		//this -> w = w;
		//this -> index = index;
	//}
	
	bool operator < (const edge & e) const {
		return w < e.w;
	}
};

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, u, v, w;
		scanf ("%d", &N);
		vector < edge > edges (N - 1);
		for (int i = 0; i < N - 1; i++) {
			scanf ("%d %d %d", &u, &v, &w);
			edges[i] = (edge) {u - 1, v - 1, w, i};
		}
		sort (edges.begin(), edges.end());
		vector < ll > ans (edges.size());
		DSU dsu (N);
		for (int i = 0; i < N; i++) {
			dsu.set (i);
		}
		for (edge e : edges) {
			ans[e.index] = dsu.merge (e.u, e.v);
		}
		for (ll a : ans) {
		printf ("%lld\n", a);
	}
	}
	
	return 0;
}
