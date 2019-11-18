#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int startVertex, endVertex, endEdge;

bool dfs (vector < vector < pair < int, int > > > & g, vector < int > & visited, vector < pair < int, int > > & parent, int s) {
	visited[s] = 1;
	for (pair < int, int > p : g[s]) {
		int u = p.first, e  = p.second;
		if (p == parent[s]) continue;
		if (visited[u] == 1) {
			// edges.push_back ({s, e});
			startVertex = u;
			endVertex = s;
			endEdge = e;
			return true;
		} else if (visited[u] == 0) {
			parent[u] = {s, e};
			if (dfs (g, visited, parent, u)) {
				// edges.push_back ({s, e});

				return true;
			}
		}
	}
	visited[s] = 2;
	return false;
}

void solve() {
	int n, m, v, u;
	cin >> n >> m;
	vector < vector < pair < int, int > > > g (2 * n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> v >> u;
		g[v].push_back ({n + u, i});
		g[n + u].push_back ({v, i});
	}
	vector < int > visited (2 * n + 1, 0);
	vector < pair < int, int > > parent (2 * n + 1, {-1, -1});
	for (int s = 1; s <= 2 * n; s++) {
		if (visited[s] == 0) {
			bool flag = dfs (g, visited, parent, s);
			if (flag) {
				vector < int > ans = {endEdge};
				for (int i = endVertex; i != startVertex; i = parent[i].first) {
					ans.push_back (parent[i].second);
				}
				if (startVertex > n) {
					ans.push_back (endEdge);
					ans.erase (ans.begin());
				}
				cout << ":)" << endl << (int) ans.size() << endl;
				for (int x : ans) {
					cout << x << " ";
				}
				cout << endl;
				return;
			}
		}
	}
	cout << ":(" << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}
