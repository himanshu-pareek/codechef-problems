#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template < typename T >
void printVector (vector < T > & vec) {
	for (T & t : vec) {
		cout << t << " ";
	}
	cout << endl;
}

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

vector < ll > cadane (vector < int > & a) {
	const int n = a.size();
	vector < ll > res;
	ll sum = 0, answer = INT_MIN;
	for (int x : a) {
		sum = max (sum + x, (ll) x);
		answer = max (answer, sum);
		res.push_back (answer);
	}
	return res;
}

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);

	vector < ll > cad = cadane (a);
	reverse (a.begin(), a.end());
	vector < ll > rev_cad = cadane (a);
	reverse (a.begin(), a.end());
	reverse (rev_cad.begin(), rev_cad.end());

	vector < ll > prefixSum, suffixSum;
	ll sum = 0LL;
	for (int x : a) {
		sum += x;
		prefixSum.push_back (sum);
	}
	for (int i = 1; i < prefixSum.size(); i++) {
		max_self (prefixSum[i], prefixSum[i - 1]);
	}
	sum = 0LL;
	for (int i = n - 1; i >= 0; i--) {
		int x = a[i];
		sum += x;
		suffixSum.push_back (sum);
	}
	reverse (suffixSum.begin(), suffixSum.end());
	for (int i = n - 2; i >= 0; i--) {
		max_self (suffixSum[i], suffixSum[i + 1]);
	}

	for (int i = 0; i < n; i++) {
		// A [i, ... , n - 1] -> rev_cad[i]
		// A [0, ... , i - 1] -> cad[i - 1]
		// [i, ..., k, k + 1, ... , n - 1, 0, 1, ..., l, .. , i - 1] (k to l) -> suffixSum[i] + prefixSum[i - 1]
		ll answer = rev_cad[i];
		if (i > 0) {
			max_self (answer, cad[i - 1]);
			max_self (answer, suffixSum[i] + prefixSum[i - 1]);
		}
		printf ("%lld ", answer);
	}

	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
