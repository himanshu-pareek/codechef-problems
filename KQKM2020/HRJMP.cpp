#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : ketek[i] QuickMatch 25
 * Contest Link : https://www.codechef.com/KQKM2020
 * Problem : Rabbo Loves Jumping [ HRJMP ]
 * Problem Link : https://www.codechef.com/KQKM2020/problems/HRJMP
 */

int main() {
	int n; long x;
	cin >> n >> x;
	vector < long > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long answer = abs (x - a[0]);
	for (int i = 0; i < n; i++) {
		answer = __gcd (answer, abs (x - a[i]));
	}
	cout << answer << endl;
	return 0;
}
