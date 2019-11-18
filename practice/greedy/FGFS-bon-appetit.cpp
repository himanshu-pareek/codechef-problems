#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using pii = pair < int, int >;
#define from first
#define to second

void add_self (int & a, int b) {
	a += b;
}

int maxNonOverlappingIntervals (vector < pii > events) {
	if (events.empty()) return 0;
	sort (events.begin(), events.end(), [&] (const pii & p1, const pii & p2) {
		return p1.to < p2.to;
	});
	int endTime = events[0].to;
	int count = 1;
	for (const pii e : events) {
		if (e.from >= endTime) {
			count++;
			endTime = e.to;
		}
	}
	return count;
}

void solve () {
	int n, k, s, f, p;
	scanf ("%d %d", &n, &k);
	//cin >> n >> k;
	map < int, vector < pii > > compartments;
	for (int i = 0; i < n; i++) {
		//cin >> s >> f >> p;
		scanf ("%d %d %d", &s, &f, &p);
		compartments[p].push_back({s, f});
	}
	int answer = 0;
	for (auto it = compartments.begin(); it != compartments.end(); it++) {
		add_self (answer, maxNonOverlappingIntervals (it -> second));
	}
	printf ("%d\n", answer);
	//cout << answer << endl;
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve ();
	}
	return 0;
}
