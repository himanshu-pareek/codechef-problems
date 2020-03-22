#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// 0 1 2 3 4 5

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > w (n);
	for (int & x : w) scanf ("%d", &x);
	int maxval = 0;
	for (int x : w) maxval = max (maxval, x);
	vector < int > ind;
	for (int i = 0; i < n; i++) {
		if (w[i] == maxval) ind.push_back (i);
	}
	int answer = 0;
	int last = ind.back();
	for (int i = 0; i < ind.size(); i++) {
		int first = ind[i];
		int diff = last - first;
		if (diff < 0) diff = n + diff;
		int count = n/2 - diff;
		answer = max (answer, count);
		last = ind[i];
	}
	cout << answer << endl;
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
