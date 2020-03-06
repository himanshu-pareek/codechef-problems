#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

vector < vector < int > > g;
vector < int > in;
vector < int > out;

void dfs1 (int u, int p = -1) {
	for (int v : g[u]) {
		if (v != p) {
			dfs1 (v, u);
			max_self (in[u], 1 + in[v]);
		}
	}
}

void dfs2 (int u, int p = -1) {
	int maxIndex = -1, secondMaxIndex = -1;
	for (int v : g[u]) {
		if (v == p) continue;
		if (maxIndex == -1 || in[v] >= in[maxIndex]) {
			secondMaxIndex = maxIndex;
			maxIndex = v;
		} else if (secondMaxIndex == -1 || in[v] >= in[secondMaxIndex]) {
			secondMaxIndex = v;
		}
	}
	for (int v : g[u]) {
		if (v == p) continue;
		int mi = maxIndex;
		if (v == maxIndex) mi = secondMaxIndex;
		int in_mi = (mi == -1) ? 0 : (2 + in[mi]);
		out[v] = max (1 + out[u], in_mi);
		dfs2 (v, u);
	}
}

int main() {
	int n, a, b;
	scanf ("%d", &n);
	vector < int > P (n + 1, true);
	for (int i = 2; i * i <= n; i++) {
		if (P[i]) {
			for (int j = i * i; j <= n; j += i) {
				P[j] = false;
			}
		}
	}
	P[0] = P[1] = false;
	g.resize (n);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d", &a, &b);
		a--, b--;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	in.assign (n, 0);
	out.assign (n, 0);
	
	dfs1 (0);
	dfs2 (0);
	
	auto isPrime = [&] (int x) {
		return P[x];
	};
	
	int root = -1;
	int height = n + 1;
	for (int i = 0; i < n; i++) {
		if (max (in[i], out[i]) < height) {
			height = max (in[i], out[i]);
			root = i;
		}
	}
	
	// We found the root
	// Now, check for validation
	vector < queue < int > > q (2);
	vector < bool > visited (n, false);
	int current = 0;
	q[current].push (root);
	visited[root] = true;
	int levels = 0;
	//for (int i = 0; i < n; i++) {
		//cout << "in[" << i << "] = " << in[i] << ", out[" << i << "] = " << out[i] << endl;
	//}
	//cout << "root = " << root << endl;
	while (!q[current].empty()) {
		vector < bool > count (n);
		while (!q[current].empty()) {
			int u = q[current].front(); q[current].pop();
			int cnt = 0;
			for (int v : g[u]) {
				if (!visited[v]) {
					q[1 - current].push (v);
					visited[v] = true;
					cnt++;
				}
			}
			if (cnt != 0 && (!isPrime (cnt) || count[cnt])) {
				cout << "NO" << endl;
				return 0;
			}
			count[cnt] = true;
		}
		current = 1 - current;
		levels++;
	}
	cout << "YES\n" << (levels - 1) << endl;
}
