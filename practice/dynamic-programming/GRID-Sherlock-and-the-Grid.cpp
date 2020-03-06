#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

void solve () {
	int n;
	scanf ("%d", & n);
	vector < string > m (n);
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	vector < bool > dp (n, true);
	int count = 0;
	bool temp = true;
	for (int i = n - 1; i >= 0; i--) {
		temp = true;
		for (int j = n - 1; j >= 0; j--) {
			dp[j] = dp[j] && (m[i][j] == '.');
			temp = temp && (m[i][j] == '.');
			count += (temp && dp[j]);
		}
	}
	printf ("%d\n", count);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
