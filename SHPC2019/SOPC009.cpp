#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int T;
	cin >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;
		vector < string > events (n);
		for (int i = 0; i < n; i++) {
			cin >> events[i];
		}
		unordered_map < string, int > m;
		for (int i = 0; i < d && i < n; i++) {
			m[events[i]]++;
		}
		int ans = m.size();
		for (int i = d; i < n; i++) {
			m[events[i]]++;
			m[events[i - d]]--;
			if (m[events[i - d]] == 0) {
				m.erase (events[i - d]);
			}
			ans = max (ans, (int) m.size());
		}
		cout << ans << endl;
	}
	return 0;
}
