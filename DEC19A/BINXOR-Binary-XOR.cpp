#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mod = 1e9 + 7;
const int mx = 1e5 + 5;
int fact[mx];

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int mul (int a, int b) {
	return (int)(((ll) a * b) % mod);
}

int power (int a, int k) {
	int answer = 1;
	while (k >= 1) {
		if (k & 1) {
			answer = mul (answer, a);
		}
		a = mul (a, a);
		k >>= 1;
	}
	return answer;
}

int inverse (int a) {
	return power (a, mod - 2);
}

void prepareFactorials () {
	fact[0] = 1;
	for (int i = 1; i < mx; i++) {
		fact[i] = mul (fact[i - 1], i);
	}
}

int getNumPerm (int n, int k) {
	int num = fact[n];
	int den = mul (fact[k], fact[n - k]);
	den = inverse (den);
	return mul (num, den);
}

void solve() {
	int n;
	string a, b;
	scanf ("%d", &n);
	cin >> a >> b;
	int a0 = 0, a1 = 0;
	for (char c : a) {
		a0 += (c == '0');
	}
	a1 = n - a0;
	int b0 = 0, b1 = 0;
	for (char c : b) {
		b0 += (c == '0');
	}
	b1 = n - b0;
	int x = min (a0, b1) + min (a1, b0);
	int y = n - (min (a0, b0) + min (a1, b1));
	int answer = 0;
	for (int k = y; k <= x; k += 2) {
		add_self (answer, getNumPerm (n, k));
	}
	printf ("%d\n", answer);
}

int main() {
	int t;
	scanf ("%d", &t);
	prepareFactorials ();
	while (t--){
		solve();
	}
	return 0;
}
