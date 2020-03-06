#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

void solve () {
	int n, k;
	scanf ("%d %d", & n, & k);
	vector < int > a (n);
	for (int & x : a) {
		scanf ("%d", & x);
	}
	vector < vector < bool > > dp (n + 1, vector < bool > (1024, false));
	dp[0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 1024; x++) {
			dp[i + 1][x] = dp[i][x] || dp[i][x ^ a[i]];
		}
	}
	int answer = 0;
	for (int i = 0; i < 1024; i++) {
		if (dp[n][i]) {
			max_self (answer, k ^ i);
		}
	}
	printf ("%d\n", answer);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
