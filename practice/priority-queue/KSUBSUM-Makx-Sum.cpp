#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int n, k1, k2, k3;
	scanf ("%d %d %d %d", &n, &k1, &k2, &k3);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	int k = max ({k1, k2, k3});
	priority_queue < int, vector < int >, greater < int > > pq;
	for (int start = 0; start < n; start++) {
		int sum = 0;
		for (int end = start; end < n; end++) {
			sum += a[end];
			if (pq.size() == k) {
				if (pq.top() < sum) {
					pq.pop();
					pq.push (sum);
				}
			} else {
				pq.push (sum);
			}
		}
	}
	vector < int > sums;
	while (!pq.empty()) {
		sums.push_back (pq.top());
		pq.pop();
	}
	printf ("%d %d %d\n", sums[k - k1], sums[k - k2], sums[k - k3]);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
