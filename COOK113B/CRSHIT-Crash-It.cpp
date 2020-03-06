#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, q, d;
	ll k, x, T;
	scanf ("%d %d %lld", &n, &q, &k);
	vector < ll > A, B;
	for (int i = 0; i < n; i++) {
		scanf ("%d %lld", &d, &x);
		if (d == 1) {
			A.push_back (x);
		} else {
			B.push_back (x);
		}
	}
	sort (A.begin(), A.end());
	sort (B.begin(), B.end());
	for (int i = 0; i < n - (int) A.size(); i++) {
		B.push_back (B[i] + k);
	}
	while (q--) {
		scanf ("%lld", &T);
		T *= 2;
		// Calculate number of crashes here
		// AC cars are stationary
		// C cars are moving with speed 1
		ll numCrashes = 0LL;
		ll rounds = T / k;
		numCrashes += rounds * (ll) A.size() * (ll)B.size() / 2;
		T %= k;
		int i = 0, j = 0;
		for (ll a : A) {
			while (i < (int) B.size() && B[i] < a) i++;
			while (j < (int) B.size() && B[j] <= T + a) j++;
			numCrashes += j - i;
		}
		printf ("%lld\n", numCrashes);
	}
	return 0;
}
			
			
