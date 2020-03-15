#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

/**
 * Contest : ketek[i] QuickMatch 25
 * Contest Link : https://www.codechef.com/KQKM2020
 * Problem : Reach at Last [ REATLAST ]
 * Problem Link : https://www.codechef.com/KQKM2020/problems/REATLAST
 */

int main() {
	int n;
	cin >> n;
	vector < int > a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	queue < pii > q;
	q.push ({0, 0});
	int answer = -1;
	set < int > s;
	for (int i = 0; i < n; i++) {
		s.insert (i);
	}
	s.erase (0);
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		if (p.first == n - 1) {
			answer = p.second;
			break;
		}
		int from, to;
		if (a[p.first] > 0) {
			from = p.first + 1, to = p.first + a[p.first];
		} else {
			from = p.first + a[p.first], to = p.first - 1;
		}
		
		auto it = s.lower_bound (from);
		while (it != s.end()) {
			 int i = *it;
			 if (i > to) break;
			 it++;
			 s.erase (i);
			 q.push ({i, p.second + 1});
		 }
	 }
	 cout << answer << endl;
	return 0;
}
