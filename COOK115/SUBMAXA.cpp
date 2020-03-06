#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

// Problem link : https://www.codechef.com/problems/SUBMAXA

vector < ll > solve2 (vector < int > & A) {
	const int n = A.size();
	vector < ll > increasing (n + 2), decreasing (n + 2), constant (n + 2);
	stack < int > s;
	vector < int > left (n, -1), right (n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && A[i] >= A[s.top()]) {
			s.pop();
		}
		if (!s.empty()) left[i] = s.top();
		s.push (i);
	}
	while (!s.empty()) s.pop();
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && A[i] > A[s.top()]) {
			s.pop();
		}
		if (!s.empty()) right[i] = s.top();
		s.push (i);
	}
	
	for (int i = 0; i < n; i++) {
		int l = i - left[i];
		int r = right[i] - i;
		if (l > r) {
			swap (l, r);
		}
		
		// 1 <= k <= l [ length of subarray ]
		// Contribution of A[i] for length k is A[i] * k
		increasing[1] += A[i];
		increasing[l + 1] -= A[i];
		
		// l + 1 <= k <= r
		// Contribution of A[i] for length k is A[i] * l
		constant[l + 1] += (ll) A[i] * l;
		constant[r + 1] -= (ll) A[i] * l;
		
		// r + 1 <= k <= r + l - 1
		// Contribution of A[i] for length k is A[i] * ((r + l) - k)
		//									  = A[i] * (r + l) - A[i] * k
		constant[r + 1] += (ll) A[i] * (r + l);
		constant[r + l] -= (ll) A[i] * (r + l);
		increasing[r + 1] -= A[i];
		increasing[r + l] += A[i];
	}
	
	vector < ll > ans (n);
	int index = 0;
	for (int i = 1; i <= n; i++) {
		constant[i] += constant[i - 1];
		increasing[i] += increasing[i - 1];
		ll sum = increasing[i] * i + constant[i];
		ans[index % n] = sum; index++;
	}
	
	return ans;
}

void solve() {
	int N;
	scanf ("%d", &N);
	vector < int > A (N);
	for (int & x : A) scanf ("%d", & x);
	vector < ll > non_circular = solve2 (A);
	for (int i = 0; i < N; i++) {
		A.push_back (A[i]);
	}
	vector < ll > both = solve2 (A);
	vector < ll > circular (N);
	for (int i = 0; i < N; i++) {
		circular[i] = both[i] - non_circular[i];
	}
	for (ll x : circular) {
		printf ("%lld ", x);
	}
	printf ("\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
