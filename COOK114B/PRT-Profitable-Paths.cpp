#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int sub (int a, int b) {
	int c = a - b;
	if (c < 0) {
		c += mod;
	}
	return c;
}

int mul (ll a, ll b) {
	a %= mod;
	b %= mod;
	return (int ) ((a * b) % mod);
}

vector < vector < int > > g;
vector < int > in;
vector < int > out;
vector < ll > paths;

void dfs1 (int u, int p) {
	int total = 0;
	for (int v : g[u]) {
		if (v != p) {
			dfs1 (v, u);
		}
		total += in[v];
	}
	if (total == 0) total = 1;
	in[u] = total;
}

void dfs2 (int u, int p) {
	vector < ll > a;
	ll sum = 0;
	a.push_back (out[u]);
	sum += out[u];
	for (int v : g[u]) {
		if (v != p) {
			a.push_back (in[v]);
			sum += in[v];
			out[v] = out[u] + in[u] - in[v];
		}
	}
	paths[u] = 0;
	for (int x : a) {
		paths[u] += x * (sum - x);
	}
	paths[u] /= 2;
	for (int v : g[u]) {
		if (v != p) {
			dfs2 (v, u);
		}
	}
	if (g[u].size() == 1 && paths[u] == 0) {
		paths[u] = out[u];
	}
}

void solve() {
	int n, u, v;
	cin >> n;
	vector < ll > A (n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	g.resize (n);
	for (int i = 0; i < n; i++) {
		g[i].resize (0);
	}
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back (v);
		g[v].push_back (u);
	}
	if (n == 1) {
		cout << A[0] << endl;
		return;
	}
	in.assign (n, 0);
	out.assign (n, 0);
	paths.assign (n, 0LL);
	dfs1 (0, -1);
	if (g[0].size() == 1) out[0] = 1;
	dfs2 (0, -1);
	//for (int i = 0; i < n; i++) {
		//cout << "in - " << in[i] << ", out - " << out[i] << ", paths - " << paths[i] << endl;
	//}
	sort (paths.begin(), paths.end());
	sort (A.begin(), A.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		add_self (ans, mul (paths[i], A[i]));
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
