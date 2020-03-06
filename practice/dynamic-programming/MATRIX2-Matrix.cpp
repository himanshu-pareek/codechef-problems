#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n, m;
	scanf ("%d %d", &n, &m);
	vector < string > A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	vector < vector < pair < ll, int > > > dp (n + 1, vector < pair < ll, int > > (m + 1, {0, 0}));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j + 1].second = (1 + min (dp[i][j + 1].second, dp[i][j].second)) * (A[i][j] - '0');
			dp[i + 1][j + 1].first = dp[i][j + 1].first + dp[i + 1][j].first
									- dp[i][j].first + dp[i + 1][j + 1].second;
		}
	}
	
	printf ("%lld\n", dp[n][m].first);
	return 0;
}

