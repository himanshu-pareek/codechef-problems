#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	assert (n == s.length());
	pii p = make_pair (0, 0);
	int i = 0;
	while (i < n) {
		if (s[i] == 'L' || s[i] == 'R') {
			if (s[i] == 'L') p.first--;
			else p.first++;
			i++;
			while (i < n && (s[i] == 'L' || s[i] == 'R')) {
				i++;
			}
		} else {
			if (s[i] == 'U') p.second++;
			else p.second--;
			i++;
			while (i < n && (s[i] == 'U' || s[i] == 'D')) {
				i++;
			}
		}
	}
	cout << p.first << " " << p.second << endl;
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
