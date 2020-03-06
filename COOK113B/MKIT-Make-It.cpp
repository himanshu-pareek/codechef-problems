#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll inf = 1e18 + 5;

int main() {
	int n, q, k, l, r;
	scanf ("%d %d %d", &n, &q, &k);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	// calculate all divisors of k
	vector < int > divisors;
	for (int i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			divisors.push_back (i);
			if (i < k / i) {
				divisors.push_back (k / i);
			}
		}
	}
	sort (divisors.begin(), divisors.end());
	int d = (int) D.size();
	
	// size of dp = n * sizeof (divisors)
	vector < vector < ll > > dp (n, vector < ll > (d, inf));
	vector < vector < ll > > pd (n, vector < ll > (d, inf));
	
	// Store index of gcd (di * dj, k) for 0 <= i < d && 0 <= j < d
	vector < vector < int > > gcd_index (d, vector < int > (d));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			int g = __gcd (1LL * divisors[i] * divisors[j], 1LL * k)
			gcd_index[i][j] = (int) (lower_bound (divisors.begin(), divisors.end(), g) - divisors.begin());
		}
	}
	
	// 
