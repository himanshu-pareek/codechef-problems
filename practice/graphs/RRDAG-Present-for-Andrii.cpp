#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n;
	scanf ("%d", &n);
	vector < vector < int > > g (n, vector < int > (n, 0));
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			g[i][j] = s[j] - '0';
		}
	}
	vector < int > outDegree (n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			outDegree[i] += g[i][j];
		}
	}
	vector < vector < int > > gr (n, vector < int > (n, 0));
	vector < bool > removed (n, false);
	int count = 0; // number of edges added
	for (int i = 0; i < n; i++) {
		// find greatest node with outdegree = 0
		// and which is not removed
		int v = -1;
		for (int j = n - 1; j >= 0; j--) {
			if (!removed[j] && outDegree[j] == 0) {
				v = j; break;
			}
		}
		if (v == -1) break;
		// Add edge from all the vertices (!= v) to v
		for (int j = 0; j < n; j++) {
			if (j != v && g[j][v] == 0 && !removed[j]) {
				gr[j][v] = 1;
				count++;
			}
		}
		// Update the outdegree of all the neighbors of v
		for (int j = 0; j < n; j++) {
			if (g[j][v] == 1) {
				outDegree[j]--;
			}
		}
		// Delete v
		removed[v] = true;
	}
	printf ("%d\n", count);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (gr[i][j] == 1) {
				printf ("%d %d\n", i + 1, j + 1);
			}
		}
	}
	return 0;
}
