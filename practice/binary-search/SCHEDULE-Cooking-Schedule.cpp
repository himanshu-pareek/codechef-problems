#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

bool check (string & s, int x, int k) {
	string a = s;
	//cout << "a = " << a << ", x = " << x << endl;
	const int n = a.size();
	int i = 0;
	while (i < n) {
		char y = a[i];
		int count = 0;
		while (i < n && a[i] == y && count < x) {
			count++; i++;
		}
		if (i < n && a[i] == y) {
			k--;
			a[i] = '0' + (1 - (y - '0'));
			// i--;
		}
	}
	return k >= 0;
}

void solve () {
	int n, k;
	scanf ("%d %d", &n, &k);
	string s;
	cin >> s;
	int low = 1, high = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (check (s, mid, k)) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	printf ("%d\n", low);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
