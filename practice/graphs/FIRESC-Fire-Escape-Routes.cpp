#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

void dfs (vector < vector < int > > & graph, int s, vector < int > & leader, int ld) {
	leader[s] = ld;
	for (int u : graph[s]) {
		if (leader[u] == -1) {
			dfs (graph, u, leader, ld);
		}
	}
}

void solve() {
	int n, m, i, j;
	scanf ("%d %d", &n, &m);
	vector < vector < int > > graph (n);
	while (m--) {
		scanf ("%d %d", &i, &j);
		i--, j--;
		graph[i].push_back (j);
		graph[j].push_back (i);
	}
	vector < int > leader (n, -1);
	for (int i = 0; i < n; i++) {
		if (leader[i] == -1) {
			dfs (graph, i, leader, i);
		}
	}
	vector < int > count (n);
	for (int x : leader) {
		count[x]++;
	}
	int cnt = 0, ans = 1;
	for (int c : count) {
		if (c > 0) {
			cnt++;
			ans = mul (ans, c);
		}
	}
	printf ("%d %d\n", cnt, ans);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
