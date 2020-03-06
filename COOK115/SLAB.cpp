#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int N;
	scanf ("%d", &N);
	int n = N;
	int tax = 0;
	if (n > 250000) {
		tax += (min (n, 500000) - 250000) * 0.05;
	}
	if (n > 500000) {
		tax += (min (n, 750000) - 500000) * 0.10;
	}
	if (n > 750000) {
		tax += (min (n, 1000000) - 750000) * 0.15;
	}
	if (n > 1000000) {
		tax += (min (n, 1250000) - 1000000) * 0.20;
	}
	if (n > 1250000) {
		tax += (min (n, 1500000) - 1250000) * 0.25;
	}
	if (n > 1500000) {
		tax += (n - 1500000) * 0.30;
	}
	printf ("%d\n", (N - tax));
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
