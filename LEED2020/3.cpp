#include <bits/stdc++.h>
using namespace std;

void solve () {
	int N, x;
	scanf ("%d %d", &N, &x);
	vector < int > A (N);
	for (int & x : A) scanf ("%d", &x);
	sort (A.begin(), A.end());
	int l = 0, r = N - 1;
	while (l < r) {
		int sum = A[l] + A[r];
		if (sum == x) {
			printf ("AVAILABLE %d %d\n", A[l], A[r]);
			return;
		} else if (sum < x) {
			l++;
		} else {
			r--;
		}
	}
	printf ("NOT AVAILABLE\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
