#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;
#define left first
#define right second

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector < pii > a (n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].left >> a[i].right;
		}
		sort (a.begin(), a.end());
		map < int, int > l, r;
		for (int i = 0; i < n; i++) {
			l[a[i].left]++; r[a[i].right]++;
		}
		map < int, int > :: iterator itl, itr;
		itl = l.begin(); itr = r.begin();
		int ans = n, current = 0;
		while (itl != l.end() && itr != r.end()) {
			if (itl -> first <= itr -> first) {
				current += itl -> second;
				itl++;
			} else {
				current -= itr -> second;
				ans = min (ans, current);
				itr++;
			}
		}
		if (ans >= n - 1) {
			cout << -1 << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
			
