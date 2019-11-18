#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e5 + 5;

void solve () {
	int n, k, m;
	scanf ("%d%d%d", &n, &k, &m);
	vector < pair < int, int > > days (n);
	for (pair < int, int > & p : days) scanf ("%d", &(p.first));
	for (pair < int, int > & p : days) scanf ("%d", &(p.second));
	vector < int > buttons (k + m);
	for (int & x : buttons) scanf ("%d", & x);
	vector < int > diff (n);
	for (int i = 0; i < n; i++) {
		diff[i] = days[i].first - days[i].second;
	}
	sort (diff.begin(), diff.end(), [&] (const int & a, const int & b) {
		return a > b;
	});
	sort (buttons.begin(), buttons.end(), [&] (const int & a, const int & b) {
		return a > b;
	});
	long answer = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j < buttons.size() && buttons[j] > diff[i]) {
			j++;
		}
		if (j == buttons.size()) {
			break;
		}
		diff[i] -= buttons[j];
		j++;
	}
	//cout << days.size() << endl;
	for (int x : diff) {
		//cout << "(" << p.first << ", " << p.second << ")" << endl;
		answer += x;
	}
	printf ("%ld\n", answer);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
