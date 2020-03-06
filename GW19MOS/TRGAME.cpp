#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < vector < int > > g;
vector < int > in;
vector < int > out;
vector < int > parent;

void dfs1 (int u, int p = -1) {
	in[u] = 1;
	parent[u] = p;
	for (int v : g[u]) {
		if (v != p) {
			dfs1 (v, u);
			in[u] += in[v];
		}
	}
}

void dfs2 (int u, int p = -1) {
	int mx = -1, smx = -1;
	for (int v : g[u]) {
		if (v != p) {
			if (mx == -1 || in[v] >= in[mx]) {
				smx = mx;
				mx = v;
			} else if (smx == -1 || in[v] > in[smx]) {
				smx = v;
			}
		}
	}
	for (int v : g[u]) {
		if (v != p) {
			int ind = mx;
			if (mx == v) ind = smx;
			out[v] = max (1 + out[u], (ind == -1) ? 0 : (2 + in[ind]));
			dfs2 (v, u);
		}
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n, a, b;
		scanf ("%d", &n);
		g.resize (n);
		for (int i = 0; i < n; i++) {
			g[i].resize (0);
		}
		for (int i = 1; i < n; i++) {
			scanf ("%d %d", &a, &b);
			a--, b--;
			g[a].push_back (b);
			g[b].push_back (a);
		}
		if (n & 1) {
			for (int i = 0; i < n; i++) {
				printf ("0");
			}
			printf ("\n");
			continue;
		}
		in.assign (n, 0);
		out.assign (n, 0);
		parent.assign (n, -1);
		dfs1 (0);
		dfs2 (0);
		for (int i = 0; i < n; i++) {
			int m = 0;
			for (int j : g[i]) {
				int sz;
				if (parent[j] == i) {
					sz = in[j];
				} else {
					sz = in[j] + out[j] - in[i];
				}
				m = max (m, sz);
			}
			if (2 * m <= n) printf ("1");
			else printf ("0");
		}
		printf ("\n");
	}
	return 0;
}

