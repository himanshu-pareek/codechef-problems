#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;

void add_self (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

vector < vector < int > > g;
vector < int > ways;
vector < bool > visited;

void dfs (int u) {
	visited[u] = true;
	for (int v : g[u]) {
		if (!visited[v]) dfs (v);
		add_self (ways[u], ways[v]);
	}
}

int main() {
	int n, m, p, q, u, v;
	scanf ("%d %d", &n, &m);
	scanf ("%d %d", &p, &q);
	p--; q--;
	g.resize (n);
	for (int i = 0; i < n; i++) {
		g[i].resize (0);
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		g[u].push_back (v);
	}
	visited.assign (n, false);
	ways.assign (n, 0);
	ways[q] = 1;
	dfs (p);
	printf ("%d\n", ways[p]);
	return 0;
}
