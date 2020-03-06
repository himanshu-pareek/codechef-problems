#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t, n;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		vector < int > A (n + 1);
		A[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &A[i]);
		}
		vector < ll > dp (n + 1);
		dp[0] = 0;
		dp[1] = A[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = max (dp[i - 1] + (ll) A[i], dp[i - 2] + (ll) A[i - 1] * A[i]);
		}
		vector < pair < int, int > > vec;
		int i = n;
		while (i > 0) {
			if (dp[i] == dp[i - 2] + (ll) A[i - 1] * A[i]) {
				vec.push_back (make_pair (i - 1, i));
				i -= 2;
			} else {
				i--;
			}
		}
		cout << dp[n] << " " << (n - (int) vec.size()) << endl;
		cout << vec.size() << endl;
		for (pair < int, int > p : vec) {
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}
