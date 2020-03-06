#include <bits/stdc++.h>
using namespace std;
using pii = pair < int, int >;
using ll = long long;

bool check (vector < int > & a, vector < int > & b, int k) {
	int n = (int) a.size();
	// compare b[i] and a[i + k]
	// i < n - 1 and i + k < n
	for (int i = 0; i < n - 1 && i + k < n; i++) {
		if (b[i] > a[i + k]) return false;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		int n, u, v, w;
		cin >> n;
		vector < int > a (n), b(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> b[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort (a.begin(), a.end());
		sort (b.begin(), b.end());
		int low = 0, high = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (check (a, b, mid)) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << low << endl;
	}
	return 0;
}
			
