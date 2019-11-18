#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int > ;
#define band first

void add_self (ll & a, ll b) {
	a += b;
}

void solve () {
	int n;
	scanf ("%d", &n);
	vector < pii > songs (n);
	for (pii & x : songs) {
		scanf ("%d %d", & (x.band), & (x.second));
	}
	sort (songs.begin(), songs.end());
	ll answer = 0, totalLength = 0;
	vector < int > s;
	for (int i = 0; i < n; i++) {
		//cout << i << " " << songs[i].band << " " << songs[i].second << endl;
		if (i == 0 || (songs[i].band > songs[i - 1].band)) {
			s.push_back (songs[i].second);
		} else {
			totalLength += songs[i].second;
		}
	}
	//cout << s.size() << endl;
	add_self (answer, totalLength * s.size());
	sort (s.begin(), s.end());
	int count = 1;
	for (int x : s) {
		add_self (answer, (ll) x * count);
		count++;
	}
	printf ("%lld\n", answer);
}

int main() {
	int T;
	scanf ("%d", & T);
	while (T--) {
		solve();
	}
	return 0;
}
