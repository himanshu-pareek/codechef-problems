#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Problem Link : https://www.codechef.com/problems/CHFDIV
 */
 
// MODULAR ARITHMATIC
const int mod = 1e9 + 7;

void add_self (int & a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int mul (int a, int b) {
	return (ll) a * b % mod;
}

int power (int n, int k) {
	// compute (n^k) rem mod
	int answer = 1;
	while (k > 0) {
		if (k & 1) answer = mul (answer, n);
		n = mul (n, n);
		k >>= 1;
	}
	return answer;
}

int inverse (int n) {
	return power (n, mod - 2);
}
 
const int mx = 1e6 + 5;
vector < int > primes;

void seive() {
	vector < bool > isPrime (mx + 1, true);
	for (int i = 2; (ll) i * i <= mx; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= mx; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= mx; i++) {
		if (isPrime[i]) {
			primes.push_back (i);
		}
	}
}

void solve() {
	int N; ll K;
	scanf ("%d %lld", &N, &K);
	int answer = 1;
	for (int p : primes) {
		if (p > N) break;
		if (K % p) {
			ll q = p;
			int sum = 0;
			while (q <= N) {
				sum += N / q;
				q *= p;
			}
			sum = power (p, sum);
			answer = mul (answer, sum);
		}
	}
	printf ("%d\n", answer);
}

int main() {
	int T;
	scanf ("%d", &T);
	seive ();
	while (T--) {
		solve();
	}
	return 0;
}
