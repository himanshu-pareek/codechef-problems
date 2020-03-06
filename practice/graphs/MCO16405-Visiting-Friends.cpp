#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 5;
vector < vector < int > > g, gr;
vector < bool > visited;
vector < int > order, id;

void dfs1 (int v) {
	visited[v] = true;
	for (int u : g[v]) {
		if (!visited[u]) {
			dfs1 (u);
		}
	}
	order.push_back (v);
}

void dfs2 (int v, int c) {
	visited[v] = true;
	id[v] = c;
	for (int u : gr[v]) {
		if (!visited[u]) {
			dfs2 (u, c);
		}
	}
}

void dfs3 (vector < set < int > > & G, vector < ll > & C, int u) {
	ll sum = 0;
	//cout << "u = " << u << endl;
	visited[u] = true;
	for (int v : G[u]) {
		//cout << "v = " << v << endl;
		if (!visited[v]) {
			dfs3 (G, C, v);
		}
		sum = max (sum, C[v]);
		//cout << "sum = " << sum << endl;
	}
	C[u] += sum;
}
	

int main() {
	ios_base::sync_with_stdio (false);
	int n, m, u, v;
	cin >> n >> m;
	g.resize (n); gr.resize (n);
	vector < int > c (n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back (v);
		gr[v].push_back (u);
	}
	visited.assign (n, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs1 (i);
		}
	}
	visited.assign (n, false);
	id.assign (n, 0);
	reverse (order.begin(), order.end());
	int N = 0;
	for (int i = 0; i < n; i++) {
		int v = order[i];
		if (!visited[v]) {
			dfs2 (v, N++);
		}
	}
	//for (int i = 0; i < n; i++) cout << id[i] << " ";
	//cout << endl;
	vector < set < int > > G (N);
	vector < ll > C (N);
	for (int i = 0; i < n; i++) {
		for (int j : g[i]) {
			if (id[i] != id[j])
				G[id[i]].insert (id[j]);
		}
		C[id[i]] += c[i];
	}
	//for (int i = 0; i < N; i++) cout << C[i] << " ";
	//cout << endl;
	visited.assign (N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs3 (G, C, i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << C[id[i]] << " ";
	}
	cout << endl;
	return 0;
}
	
