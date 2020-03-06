#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s;
	cin >> n >> s;
	assert (n == s.length());
	bool possible = true;
	int left = 0, right = n - 1;
	vector < bool > swapped (n, false);
	int count = 0;
	while (left < right) {
		if (s[left] != s[right]) {
			int l = left + 1, r = right - 1;
			if (l > r) {
				possible = false;
				break;
			}
			if (s[left] == s[r] && !swapped[right] && !swapped[r]) {
				swap (s[right], s[r]); count++;
				swapped[right] = swapped[r] = true;
			} else if (s[right] == s[l] && !swapped[left] && !swapped[l]) {
				swap (s[left], s[l]); count++;
				swapped[left] = swapped[l] = true;
			} else {
				possible = false;
				break;
			}
		}
		left++, right--;
	}
	if (possible) {
		cout << "YES" << endl << count << endl;
	} else {
		cout << "NO" << endl;
	}
}
		
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
