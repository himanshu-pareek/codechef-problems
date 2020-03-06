#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (int) (((ll) a * b) % mod);
}

int power (int a, int k) {
	int ans = 1;
	while (k >= 1) {
		if (k & 1) ans = mul (ans, a);
		a = mul (a, a);
		k >>= 1;
	}
	return ans;
}

int inverse (int a) {
	return power (a, mod - 2);
}

void solve () {
	int N;
	scanf ("%d", &N);
	string s;
	cin >> s;
	assert (s.size() == N);
	vector < int > dp (2 * N + 1);
	int o = N;
	int total = 0;
	int i = 0;
	for (char c : s) {
		dp[o]++;
		if (c == '(') {
			o--;
		} else if (c == ')') {
			o++;
			add_self (total, mul (dp[o - 1], N - i));
			dp[o + 1] += dp[o - 1];
			dp[o - 1] = 0;
		}
		i++;
	}
	total = mul (total, 2);
	int deno = mul (N, N + 1);
	int answer = mul (total, inverse (deno));
	printf ("%d\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
		solve();
	}	
	return 0;
}

