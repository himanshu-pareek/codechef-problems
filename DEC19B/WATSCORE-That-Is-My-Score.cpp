#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		int n, p, s;
		vector < int > score (11);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p >> s;
			p--;
			score[p] = max (score[p], s);
		}
		int ans = 0;
		for (int i = 0; i < 8; i++) {
			ans += score[i];
		}
		cout << ans << endl;
	}
	return 0;
}
