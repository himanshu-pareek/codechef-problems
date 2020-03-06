#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; char c;
	cin >> n >> k;
	vector < bool > a (n);
	for (int i = 0; i < n; i++) {
		cin >> c;
		a[i] = (c == 'H');
	}
	bool flag = false;
	int i, cnt;
	for (i = n - 1, cnt = 0; i >= 0 && cnt < k; i--, cnt++) {
		if (a[i]) {
			for (int j = 0; j < i; j++) {
				a[j] = !a[j];
			}
		}
	}
	int ans = 0;
	for (; i >= 0; i--) {
		ans += a[i];
	}
	cout << ans << endl;
}
		
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
