#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll inf = 1e18 + 5;

bool check (vector < ll > & a, int c, int k, int x) {
	//cout << c << " " << k << " " << x << endl;
	if (x == 0) return true;
	vector < pair < int, ll > > count (x, {0, 0LL});
	int currentIndex = 0;
	for (ll y : a) {
		if (count[currentIndex].first == k) return 1;
		if ((count[currentIndex].first == 0) || 
			(count[currentIndex].second <= inf / c && y >= c * count[currentIndex].second)) {
			count[currentIndex].first++;
			count[currentIndex].second = y;
			currentIndex = (currentIndex + 1) % x;
		}
	}
	return count[x - 1].first >= k;
	//return 0;
}

void solve() {
	int n, k, c;
	scanf ("%d %d %d", &n, &k, &c);
	vector < ll > a (n);
	for (ll & x : a) scanf ("%lld", & x);
	sort (a.begin(), a.end());
	int left = 0, right = n / k;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (check (a, c, k, mid)) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	printf ("%d\n", right);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
	 solve();
	}
	return 0;
}
