#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e5 + 5;

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	sort (a.begin(), a.end());
	int index1 = -1;
	for (int i = n - 1; i > 0; i--) {
		if (a[i] == a[i - 1]) {
			index1 = i;
			break;
		}
	}
	if (index1 == -1) {
		printf ("-1\n"); return;
	}
	int index2 = -1;
	for (int i = index1 - 2; i > 0; i--) {
		if (a[i] == a[i - 1]) {
			index2 = i;
			break;
		}
	}
	if (index2 == -1) {
		printf ("-1\n"); return;
	}
	printf ("%d\n", a[index1] * a[index2]);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
