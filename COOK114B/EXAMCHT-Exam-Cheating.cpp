#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	a--, b--;
	int n = abs (a - b);
	// count number of divisors of n
	int ans = 0;
	//cout << n << endl;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans++;
			if (i != n / i) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
