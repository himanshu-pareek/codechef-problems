#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using pii = pair < int, int >;
#define weight first
#define cost second

void add_self (int & a, int b) {
	a += b;
}

void solve () {
	int n, w, c;
	scanf ("%d", &n);
	vector < int > ones, twos;
	ll M = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &w, &c);
		if (w == 1) {
			ones.push_back (c);
		} else {
			twos.push_back (c);
		}
		M += w;
	}
	sort (ones.begin(), ones.end());
	sort (twos.begin(), twos.end());
	int i = (int) ones.size() - 1, j = (int) twos.size() - 1;
	//cout << i << " " << j << endl;
	vector < ll > answer (M + 1, 0);
	answer[0] = 0;
	ll current = 0;
	for (int weight = 2; weight <= M; weight += 2) {
		int cost1 = 0, cost2 = 0;

		if (j >= 0) {
			cost1 = twos[j];
		}
		if (i >= 1) {
			cost2 = ones[i] + ones[i - 1];
		} else if (i >= 0) {
			cost2 = ones[i];
		}

		if (cost1 > cost2) {
			current += cost1;
			j--;
		} else {
			current += cost2;
			if (i >= 1) {
				i -= 2;
			} else {
				i--;
			}
		}

		answer[weight] = current;
	}
	i = (int) ones.size() - 1, j = (int) twos.size() - 1;
	current = 0;
	if (i >= 0) {
		current = ones[i];
		answer[1] = current;
		i--;
	}
	for (int weight = 3; weight <= M; weight += 2) {
		int cost1 = 0, cost2 = 0;

		if (j >= 0) {
			cost1 = twos[j];
		}
		if (i >= 1) {
			cost2 = ones[i] + ones[i - 1];
		} else if (i >= 0) {
			cost2 = ones[i];
		}

		if (cost1 > cost2) {
			current += cost1;
			j--;
		} else {
			if (i >= 1) {
				i -= 2;
			} else {
				i--;
			}
		}

		answer[weight] = current;
	}

	//printf ("\n");
	for (int i = 1; i <= M; i++) {
		if (i > 1) printf (" ");
		printf ("%lld", answer[i]);
	}

	printf ("\n");
}

int main() {
	int T;
	//scanf ("%d", &T);
	T = 1;
	while (T--) {
		solve ();
	}
	return 0;
}
