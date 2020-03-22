#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// 0 1 2 3 4 5

const int mod = 1e9 + 7;
void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) a += mod;
}

int mul (int a, int b) {
	return (ll) a * b % mod;
}

int power (int n, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1) ans = mul (ans, n);
		n = mul (n, n);
		k >>= 1;
	}
	return ans;
}

//int power 

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > b (n);
	for (int & x : b) scanf ("%d", &x);
	int answer = 1;
	int currentA = b[0];
	for (int i = 1; i < n; i++) {
		int newA = currentA;
		for (int bit = 0; bit < 30; bit++) {
			if ((currentA >> bit) & 1) {
				if ((b[i] >> bit) & 1) {
					answer = mul (answer, 2);
				} else {
					answer = 0;
					break;
				}
			} else if ((b[i] >> bit) & 1) {
				currentA |= (1 << bit);
			}
		}
		if (answer == 0) break;
	}
	printf ("%d\n", answer);
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
