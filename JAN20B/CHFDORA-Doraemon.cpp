#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void min_self (int & a, int b) {
	if (a > b) a = b;
}

bool isValid (pair < int, int > p, int m, int n) {
	int x = p.first, y = p.second;
	return x >= 0 && y >= 0 && x < m && y < n;
}

void solve() {
	int m, n;
	scanf ("%d %d", &m, &n);
	vector < vector < int > > A (m, vector < int > (n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &A[i][j]);
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pair < int, int > left, right, top, bottom;
			left = right = top = bottom = make_pair (i, j);
			int len = 0;
			while (isValid (left, m, n) && isValid (right, m, n) &&
					isValid (top, m, n) && isValid (bottom, m, n)) {
				if (A[left.first][left.second] == A[right.first][right.second]
					&& A[top.first][top.second] == A[bottom.first][bottom.second]) {
						len++;
						left.second--;
						right.second++;
						top.first--;
						bottom.first++;
				} else {
					break;
				}
			}
			ans += len;
		}
	}
	
	printf ("%lld\n", ans);
	
}

int main() {
	int t;
	t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

