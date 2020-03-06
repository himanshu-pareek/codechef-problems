#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

set < int > s;

void solve() {
	int choice, x;
	scanf ("%d %d", &choice, &x);
	if (choice == 1) {
		s.insert (x);
	} else if (choice == 2) {
		if (s.count (x)) {
			printf ("Yes\n");
		} else {
			printf ("No\n");
		}
	} else {
		auto it = s.upper_bound (x);
		if (it == s.end()) {
			printf ("-1\n");
		} else {
			printf ("%d\n", *it);
		}
	}
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
