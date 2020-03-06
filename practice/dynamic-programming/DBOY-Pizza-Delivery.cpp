#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void max_self (int & a, int b) {
	if (a < b) a = b;
}

void min_self (int & a, int b) {
	if (a > b) a = b;
}

void add_self (int & a, int b) {
	a += b;
}

//int dp[

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > h (n), k (n);
	for (int & x : h) scanf ("%d", & x);
	for (int & x : k) scanf ("%d", & x);
	int maxH = 0;
	for (int x : h) max_self (maxH, x);
	vector < int > dp (2 * maxH + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		// Don't take k[i]
		// vector < int > new_dp = dp;
		
		// Now take k[i]
		for (int j = k[i]; j <= 2 * maxH; j++) {
			if (dp[j - k[i]] != INT_MAX) {
				min_self (dp[j], dp[j - k[i]] + 1);
			}
		}
		
		// dp = new_dp;
	}
	int answer = 0;
	for (int x : h) {
		add_self (answer, dp[2 * x]);
		//printf ("%d ", dp[2 * x]);
	}
	printf ("%d\n", answer);
}

int main() {
	int t;
	scanf ("%d", & t);
	while (t--) {
		solve ();
	}
	return 0;
}
