#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, x;
	cin >> n;
	int minimum = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> x;
		minimum = min (minimum, x);
	}
	cout << minimum << endl;
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
