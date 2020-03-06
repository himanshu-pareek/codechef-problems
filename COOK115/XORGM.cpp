#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n), b (n);
	for (int & x : a) scanf ("%d", &x);
	for (int & x : b) scanf ("%d", &x);
	int x = 0;
	for (int i = 0; i < n; i++) {
		x = x ^ (a[i] ^ b[i]);
	}
	vector < int > c (n), d (n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] ^ x;
		d[i] = c[i];
	}
	sort (b.begin(), b.end());
	sort (d.begin(), d.end());
	for (int i = 0; i < n; i++) {
		if (b[i] != d[i]) {
			printf ("-1\n");
			return;
		}
	}
	for (int x : c) {
		printf ("%d ", x);
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
