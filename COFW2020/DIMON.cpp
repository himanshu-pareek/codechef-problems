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

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int a) {
	return power (a, mod - 2);
}

int choose (int n, int r) {
	int ans = 1;
	while (n > 0 && r > 0) {
		ans = mul (ans, mul (n, inverse (r)));
		n--, r--;
	}
	return ans;
}

int main() {
	int M, K;
	scanf ("%d %d", &M, &K);
	vector < int > r (K);
	for (int & x : r) scanf ("%d", & x);
	ll R = 0;
	for (int x : r) R += x;
	ll m = M - R;
	if (m < 0) {
		printf ("0\n");
		return 0;
	}
	// answer is (m + k - 1, k - 1)
	int ans = choose ((int) m + K - 1, K - 1);
	printf ("%d\n", ans);
	return 0;
}

