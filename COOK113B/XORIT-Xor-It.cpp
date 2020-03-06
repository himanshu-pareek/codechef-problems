#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

ll G (int N) {
	// This will basically calculate G (0, N)
	ll current = 1LL << 32;
	ll num1 = 0, num2 = 0;
	// num1 - without exclusion
	// num2 - with exclusion
	ll toSub = 0LL;
	while (current) {
		ll num = N / current;
		num2 = num - num1;
		num1 = num;
		if (num2 > 0) {
			toSub += current + 1;
			toSub += current * (num2 - 1);
		}
		current >>= 1;
	}
	
	ll sum = (ll) N * (N + 1) / 2LL;
	//cout << N << ": " << sum << " " << toSub << endl;
	return sum - toSub;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << G (r) - G (l - 1) << endl;
	}
	return 0;
}
