#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Problem Link : https://www.codechef.com/problems/PEPPERA
 */

void solve() {
	int n;
	cin >> n;
	vector < string > pizza (n);
	for (string & s : pizza) {
		cin >> s;
	}
	//for (string & s : pizza) {
		//cout << s << endl;
	//}
	vector < set < pii > > possible (n);
	for (int i = 0; i < n; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < n / 2; j++) {
			left += pizza[i][j] == '1';
		}
		for (int j = n / 2; j < n; j++) {
			right += pizza[i][j] == '1';
		}
		//cout << i << ", " << left << " , " << right;
		int d = left - right;
		for (int c : {-1, 1}) {
			int diff = c * d;
			//for (auto *it = possible[i - 1].begin(); it != possible[i - 1]
			if (i > 0) {
				for (pii p : possible[i - 1]) {
					possible[i].insert ({diff + p.first, c});
				}
			} else {
				possible[i].insert ({diff, c});
			}
		}
	}
	//return;
	//for (pii p : possible[n - 1]) {
		//cout << "[ " << p.first << ", " << p.second << " ]" << endl;
	//}
	pii P;
	for (int delta = 0; ; delta++) {
		bool found = false;
		for (int diff : {-delta, delta}) {
			for (int c : {-1, 1}) {
				if (possible[n - 1].count ({diff, c})) {
					P = make_pair (diff, c);
					found = true;
					break;
				}
			}
			if (found) break;
		}
		if (found) {
			break;
		}
	}
	
	vector < string > new_pizza (n);
	for (int i = n - 1; i >= 0; i--) {
		int left = 0, right = 0;
		for (int j = 0; j < n / 2; j++) {
			left += pizza[i][j] == '1';
		}
		for (int j = n / 2; j < n; j++) {
			right += pizza[i][j] == '1';
		}
		int diff = left - right;
		if (P.second == -1) {
			reverse (pizza[i].begin(), pizza[i].end());
			diff = -diff;
		}
		P.first -= diff;
		if (i > 0) {
			if (possible[i - 1].count ({P.first, -1})) P.second = -1;
			else P.second = 1;
		}
	}
	for (string & s : pizza) {
		cout << s << endl;
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
