#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

ll power (ll a, int n) {
	ll answer = 1LL;
	while (n >= 1) {
		if (n & 1) answer *= a;
		a *= a;
		n >>= 1;
	}
	return answer;
}

void solve() {
	int n, ans;
	ll s, a, b, c, d, e;
	scanf ("%d", &n);
	scanf ("%lld", &a);
	s = a + 2 * power (10LL, n);
	printf ("%lld\n", s);
	fflush (stdout);
	scanf ("%lld", &b);
	c = power (10LL, n) - b;
	printf ("%lld\n", c);
	fflush (stdout);
	scanf ("%lld", &d);
	e = power (10LL, n) - d;
	printf ("%lld\n", e);
	fflush (stdout);
	scanf ("%d", &ans);
	if (ans == -1) {
		exit (0);
	}
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

