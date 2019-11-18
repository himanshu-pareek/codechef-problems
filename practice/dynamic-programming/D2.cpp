#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void max_self (int & a, int b) {
	a = max (a, b);
}

void printVector (vector < int > & vec) {
	for (int x : vec) {
		cout << x << " ";
	}
	cout << endl;
}

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > a (2 * n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		a[n + i] = a[i];
	}
	vector < int > dp (2 * n, 1);
	int answer = 1;
	int index = 0;
	printVector (a);
	for (int i = 2 * n - 1; i >= 0; i--) {
		for (int j = min (i + n - 1, 2 * n - 1); j > i; j--) {
			if (a[i] < a[j]) {
				max_self (dp[i], dp[j] + 1);
			}
		}
	}
	printVector (dp);
	for (int i = 0; i < n; i++) {
		if (dp[i] > answer) {
			index = i;
			answer = dp[i];
		}
	}
	printf ("%d\n", index + 1);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve ();
	}
	return 0;
}
