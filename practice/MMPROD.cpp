#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void sub_self (int & a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int mul (int a, int b) {
	int c = ((ll) a * b) % mod;
	while (c < 0) {
		c += mod;
	}
	while (c >= mod) {
		c -= mod;
	}
	return c;
}

int power (int a, int n) {
	int answer = 1;
	while (n >= 1) {
		if (n % 2) {
			answer = mul (answer, a);
		}
		a = mul (a, a);
		n >>= 1;
	}
	return answer;
}

int inverse (int a) {
	return power (a, mod - 2);
}

void self_max (int & a, int b) {
	a = max (a, b);
}

void swap (int & a, int & b) {
	a ^= b ^= a ^= b;
}

void solve () {
	int n, k;
	cin >> n >> k;
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	//for (int i = 0; i < n; i++) {
		//sub_self (a[i], 0);
	//}
	sort (a.begin(), a.end(), [&] (const int & a, const int & b) {
		return abs (a) < abs (b);
	});
	int start = n - k, end = n - 1;
	int neg = 0;
	int from = start, to = end;
	for (int i = start; i <= end; i++) {
		if (a[i] == 0) {
			neg = 0; break;
		}
		neg += (a[i] < 0);
	}
	if (neg % 2) {
		int i1 = -1, i2 = -1, j1 = -1, j2 = -1;
		for (int i = start; i <= end; i++) {
			if (a[i] > 0) {
				i1 = i;
				break;
			}
		}
		for (int i = start; i <= end; i++) {
			if (a[i] < 0) {
				j1 = i;
				break;
			}
		}
		for (int i = start - 1; i >= 0; i--) {
			if (a[i] < 0) {
				i2 = i;
				break;
			}
		}
		for (int i = start - 1; i >= 0; i--) {
			if (a[i] > 0) {
				j2 = i;
				break;
			}
		}
		int i, j;
		if ((i1 == -1 || i2 == -1) && (j1 == -1 || j2 == -1)) {
			from = 0, to = k - 1;
		} else {
			if (i1 == -1 || i2 == -1) {
				i = j1, j = j2;
			} else if (j1 == -1 || j2 == -1) {
				i = i1, j = i2;
			} else {
				if ((ll) a[i2] * a[j1] < (ll) a[j2] * a[i1]) {
					i = j1, j = j2;
				} else {
					i = i1, j = i2;
				}
			}
			swap (a[i], a[j]);
		}
	}

	//int answer = 1;
	int prod = 1;
	for (int i = from; i <= to; i++) {
		prod = mul (prod, a[i]);
	}
	//answer = prod;
	//for (int i = k; i < n; i++) {
		//prod = mul (prod, a[i]);
		//prod = mul (prod, inverse (a[i - k]));
		//self_max (answer, prod);
	//}
	cout << prod << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
