#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	int s, w1, w2, w3;
	scanf ("%d %d %d %d", &s, &w1, &w2, &w3);
	if (w1 + w2 + w3 <= s) {
		printf ("1\n");
	} else if (w1 + w2 <= s || w2 + w3 <= s) {
		printf ("2\n");
	} else {
		printf ("3\n");
	}
}

int main() {
	int t;
	t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

