#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

bool check (vector < int> & a, int x) {
	const int n = a.size();
	if (x == 1) return true;
	int prev = 0;
	int curr;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (!flag) {
			if (a[i] < prev + 1) {
				curr = a[i];
			} else {
				curr = prev + 1;
			}
		} else {
			if (a[i] < prev - 1) {
				curr = a[i];
				flag = false;
			} else {
				curr = prev - 1;
			}
		}
		if (flag && curr == 1) {
			return true;
		} else if (curr == x) {
			flag = true;
		}
		prev = curr;
	}
	return false;
}

void solve() {
	int n;
	scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) {
		scanf ("%d", & x);
	}
	/*
	 * 1,2,3,....,x-1,x,x-1,....,3,2,1
	 * ==> 2 * (x - 1) + 1 = 2 * x - 1 <= n
	 * ==> x <= (n + 1) / 2
	 */
	int low = 0, high = (n + 1) / 2;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (check (a, mid)) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	ll sum = 0;
	for (int x : a) {
		sum += x;
	}
	//cout << high << endl;
	printf ("%lld\n", sum - ((ll) high * high));
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}


