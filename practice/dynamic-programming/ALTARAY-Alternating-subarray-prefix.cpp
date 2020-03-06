#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < int > dp (n);
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		bool x = a[i + 1] > 0;
		bool y = a[i] > 0;
		if (x ^ y) {
			dp[i] = dp[i + 1] + 1;
		} else {
			dp[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf ("%d ", dp[i]);
	}
	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve ();
	}
	return 0;
}
