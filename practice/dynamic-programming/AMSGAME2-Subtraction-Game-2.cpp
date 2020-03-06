#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e4 + 5;

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}

// pos = 1 to n - 1
// current_gcd = gcd of taken elements from i = 0 to i = pos - 1
ll f (int pos, int current_gcd, vector < vector < ll > > & dp, vector < int > & a) {
	if (pos == a.size()) return (ll) (current_gcd == 1);
	if (dp[pos][current_gcd] != -1) return dp[pos][current_gcd];
	return dp[pos][current_gcd] = f (pos + 1, current_gcd, dp, a) + f (pos + 1, gcd (current_gcd, a[pos]), dp, a);
}
	

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < vector < ll > > dp (n, vector < ll > (mx, -1));
	ll answer = 0;
	for (int i = 0; i < n; i++) {
		answer += f (i, a[i], dp, a);
	}
	printf ("%lld\n", answer / 2);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

