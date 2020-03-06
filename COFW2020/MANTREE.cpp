#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < vector < int > > g;
vector < ll > bq;
vector < int > beauty;

void dfs (int u, int p = -1) {
	ll sum = 0LL;
	for (int v : g[u]) {
		if (v != p) {
			dfs (v, u);
			sum += bq[v];
		}
	}
	bq[u] = sum + beauty[u];
}

int main() {
	int N, Q, u, v;
	ll x;
	scanf ("%d %d", &N, &Q);
	beauty.resize (N);
	for (int & x : beauty) scanf ("%d", & x);
	g.resize (N);
	for (int i = 1; i < N; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		g[u].push_back (v);
		g[v].push_back (u);
	}
	bq.resize (N);
	dfs (0);
	vector < pair < ll, int > > P;
	for (int i = 0; i < N; i++) {
		P.push_back (make_pair (bq[i], i));
	}
	sort (P.begin(), P.end());
	auto search = [&] (ll y) {
		int low = 0, high = N - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (P[mid].first >= y) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return low;
	};
	while (Q--) {
		scanf ("%lld", &x);
		int index = search (x);
		if (index == N) index = -2;
		else index = P[index].second;
		printf ("%d\n", index + 1);
	}
	return 0;
}
