#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define MAX_VALID 1000000000000ll

ll computeNumber (string s, int B) {
	ll ans = 0, p = 1;
	for (char c : s) {
		int digit = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
		if (digit >= B) return -1;
		ans = ans * B + digit;
		if (ans > MAX_VALID) return -1;
	}
	return ans;
} 

void updateMaps (map < ll, int > &m1, map < int, set < ll > > &m2, ll num) {
	int freq;
	if (num < 0) {
		return;
	}
	if (m1.find (num) == m1.end()) {
		freq = 0;
	} else {
		freq = m1[num];
	}
	m1[num] = freq + 1;
	if (freq > 0) {
		m2[freq].erase (num);
	}
	m2[freq + 1].insert (num);
}

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector < pair < int, string > > numbers (N);
		for (int i = 0; i < N; i++) {
			cin >> numbers[i].first >> numbers[i].second;
		}
		map < ll, int > m1;
		map < int, set < ll > > m2;
		for (int i = 0; i < N; i++) {
			string s = numbers[i].second;
			int base = numbers[i].first;
			if (s == "0") {
				updateMaps (m1, m2, 0);
				continue;
			}
			if (base != -1) {
				updateMaps (m1, m2, computeNumber (s, base));
				continue;
			}
			for (base = 2; base <= 36; base++) {
				updateMaps (m1, m2, computeNumber (s, base));
			}
		}
		ll ans;
		// cout << "Here" << endl;
		
		if (m2[N].empty()) {
			ans = -1;
		} else {
			ans = *(m2[N].begin());
		}
		cout << ans << endl;
	}
	return 0;
}

