#include <bits/stdc++.h>
using namespace std;

int f (string & s, char zero, char one) {
	const int n = (int) s.size();
	vector < int > cnt (n);
	cnt[0] = (s[0] == zero);
	for (int i = 1; i < n; i++) {
		cnt[i] = cnt[i - 1] + (s[i] == zero);
	}
	int ans = n;
	int total_zeros = cnt[n - 1];
	int total_ones = n - total_zeros;
	//cout << s << " " << total_zeros << " " << total_ones << endl;
	for (int l = 0; l < n; l++) {
		int cnt_zeros_left = l > 0 ? cnt[l - 1] : 0;
		int cnt_ones_left = l - cnt_zeros_left;
		for (int r = l; r < n; r++) {
			int cnt_zeros_mid = cnt[r] - cnt_zeros_left;
			int cnt_ones_mid = r - l + 1 - cnt_zeros_mid;
			int cnt_zeros_right = total_zeros - (cnt_zeros_left + cnt_zeros_mid);
			int cnt_ones_right = total_ones - (cnt_ones_left + cnt_ones_mid);
			ans = min (ans, cnt_ones_left + cnt_zeros_mid + cnt_ones_right);
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		// code here
		int x = f (s, '0', '1');
		int y = f (s, '1', '0');
		cout << min (x, y) << endl;
	}
	return 0;
}
