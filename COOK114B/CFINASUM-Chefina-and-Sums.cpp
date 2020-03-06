#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector < ll > A (n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	vector < ll > P (n);
	P[0] = A[0];
	for (int i = 1; i < n; i++) {
		P[i] = P[i - 1] + A[i];
	}
	ll sum = P[n - 1];
	vector < pair < ll, int > > indices;
	for (int i = 0; i < n; i++) {
		indices.push_back (make_pair (A[i], i));
	}
	sort (indices.begin(), indices.end());
	//for (pair < ll, int > ind : indices) {
		//cout << ind.first << " " << ind.second << endl;
	//}
	auto firstOccurance = [&] (ll x) {
		int low = 0, high = n - 1;
		int ans = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (indices[mid].first == x) {
				ans = mid;
				high = mid - 1;
			} else if (indices[mid].first > x) high = mid - 1;
			else low = mid + 1;
		}
		//cout << "firstOccurance of " << x << " is " << ans << endl;
		return ans;
	};
	auto lastOccurance = [&] (ll x) {
		int low = 0, high = n - 1;
		int ans = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (indices[mid].first == x) {
				ans = mid;
				low = mid + 1;
			} else if (indices[mid].first > x) high = mid - 1;
			else low = mid + 1;
		}
		//cout << "lastOccurance of " << x << " is " << ans << endl;
		return ans;
	};
	auto searchLeft = [&] (int index, ll x) {
		int low = 0, high = n - 1;
		int first = firstOccurance (x);
		if (first == -1 || indices[first].second > index) return 0;
		low = first;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (indices[mid].first > x) {
				high = mid - 1;
			} else if (indices[mid].first < x) {
				low = mid + 1;
			} else if (indices[mid].second <= index) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		//cout << "From Search Left: " << high - first + 1 << endl;
		// from first to high
		return high - first + 1;
	};
	auto searchRight = [&] (int index, ll x) {
		int low = 0, high = n - 1;
		int last = lastOccurance (x);
		if (last == -1 || indices[last].second < index) return 0;
		high = last;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (indices[mid].first > x) {
				high = mid - 1;
			} else if (indices[mid].first < x) {
				low = mid + 1;
			} else if (indices[mid].second >= index) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		//cout << "From Search Right: " << last - low + 1 << endl;
		// from low to last
		return last - low + 1;
	};
	ll ways = 0LL;
	for (int i = 0; i < n - 1; i++) {
		ll leftSum = P[i];
		ll rightSum = sum - leftSum;
		ways += searchLeft (i, leftSum - rightSum);
		ways += searchRight (i + 1, rightSum - leftSum);
	}
	cout << ways << endl;
}

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
