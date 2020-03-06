#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < int > s;
	for (int x : a) {
		int left = 0, right = (int)s.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (s[mid] > x) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		if (left == s.size()) {
			s.push_back (x);
		} else {
			s[left] = x;
		}
	}
	
	printf ("%d", (int)s.size());
	for (int x : s) {
		printf (" %d", x);
	}
	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

