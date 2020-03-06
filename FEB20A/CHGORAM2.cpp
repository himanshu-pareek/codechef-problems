#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 2e5 + 10;
int n, s[mx];
vector < int > g[mx];
vector < ll > dp1[mx], dp2[mx];
ll answer;

void dfs (int u = 0, int p = -1) {
	dp1[u] = {s[u]}, dp2[u] = {0};
	for (int v : g[u]) {
		if (v != p) {
			dfs (v, u);
			// Move v one level up
			dp1[v].push_back (0);
			dp2[v].pop_back ();
			if (dp1[v].size() > dp1[u].size()) {
				// swap dp[u] and dp[v]
				swap (dp1[u], dp1[v]);
				swap (dp2[u], dp2[v]);
			}
			if (dp2[u].size() < dp1[v].size()) {
				// insert required zeros at the beginning of dp2[u]
				// because we are processing in reverse order
				vector < int > p (dp1[v].size() - dp2[u].size(), 0);
				dp2[u].insert (dp2[u].begin(), p.begin(), p.end());
			}
			for (int i = 1; i <= dp1[v].size(); i++) {
				answer += dp1[v][dp1[v].size() - i] * dp2[u][dp2[u].size() - i];
			}
			for (int i = 1; i <= dp2[v].size(); i++) {
				answer += dp2[v][dp2[v].size() - i] * dp1[u][dp1[u].size() - i];
			}
			for (int i = 1; i <= dp1[v].size(); i++) {
				dp2[u][dp2[u].size() - i] += dp1[u][dp1[u].size() - i] * dp1[v][dp1[v].size() - i];
			}
			for (int i = 1; i <= dp1[v].size(); i++) {
				dp1[u][dp1[u].size() - i] += dp1[v][dp1[v].size() - i];
			}
			for (int i = 1; i <= dp2[v].size(); i++) {
				dp2[u][dp2[u].size() - i] += dp2[v][dp2[v].size() - i];
			}
		}
	}
	g[u].clear();
}			

void solve () {
	int n, u, v;
	scanf ("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		g[u].push_back (v);
		g[v].push_back (u);
	}
	for (int i = 0; i < n; i++) {
		scanf ("%d", &s[i]);
	}
	answer = 0LL;
	dfs ();
	printf ("%lld\n", 6 * answer);
}
	

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve ();
	}
	return 0;
}
