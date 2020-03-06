#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < int > a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int count0 = 0, count2 = 0;
		for (int x : a) {
			count0 += x == 0;
			count2 += x == 2;
		}
		ll ans = 0;
		ans = (ll) count0 * (count0 - 1) / 2LL;
		ans += (ll) count2 * (count2 - 1) / 2LL;
		cout << ans << endl;
	}
	return 0;
}

