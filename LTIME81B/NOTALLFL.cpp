#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector < int > occurances (k + 1);
	int start = 0, end = -1;
	int count = 0, answer = 0;
	for (end = 0; end < n; end++) {
		if (occurances[a[end]] == 0) {
			count++;
		}
		occurances[a[end]]++;
		while (count >= k) {
			occurances[a[start]]--;
			if (occurances[a[start]] == 0) {
				count--;
			}
			start++;
		}
		answer = max (answer, end - start + 1);
	}
	cout << answer << endl;
}
		
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
