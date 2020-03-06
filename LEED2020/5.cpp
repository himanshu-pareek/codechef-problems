#include <bits/stdc++.h>
using namespace std;

void recurse (vector < vector < int > > & A, vector < int > & minIndex, int diff) {
	int m = A.size();
	int n = A[0].size();
	int num_rows = (m + diff - 1) / diff;
	if (num_rows <= 2) {
		// base case [ calculate leftmost min index yourself ]
		for (int i = 0; i < m; i += diff) {
			int minInd = 0;
			for (int j = 1; j < n; j++) {
				if (A[i][j] < A[i][minInd]) {
					minInd = j;
				}
			}
			minIndex[i] = minInd;
		}
		return;
	}
	recurse (A, minIndex, diff << 1);
	for (int i = diff; i < m; i += (diff << 1)) {
		int prev_row = i - diff, next_row = min (i + diff, m - 1);
		int from = minIndex[prev_row], to = minIndex[next_row];
		int minInd = from;
		for (int j = from + 1; j <= to; j++) {
			if (A[i][j] < A[i][minInd]) {
				minInd = j;
			}
		}
		minIndex[i] = minInd;
	}
}

void solve () {
	int m, n;
	cin >> m >> n;
	vector < vector < int > > A (m, vector < int > (n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	vector < int > minIndex (m, n - 1);
	recurse (A, minIndex, 1);
	for (int i = 0; i < m; i++) {
		printf ("%d ", A[i][minIndex[i]]);
	}
	printf ("\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
