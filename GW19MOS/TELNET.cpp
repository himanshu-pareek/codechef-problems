#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int inf = 1e8 + 5;

int dist (pii a, pii b) {
	return abs (a.first - b.first) + abs (a.second - b.second);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, K;
		scanf ("%d %d", &N, &K);
		vector < vector < int > > H (N, vector < int > (N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> H[i][j];
			}
		}
		vector < vector < pii > > locations (K + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				locations[H[i][j]].push_back (make_pair (i, j));
			}
		}
		vector < vector < int > > d (N, vector < int > (N, inf));
		set < pair < int, pii > > s;
		for (pii p : locations[1]) {
			s.insert (make_pair (0, p));
			d[p.first][p.second] = 0;
		}
		pair < int, pii > pp;
		while (!s.empty()) {
			pp = *s.begin(); s.erase (pp);
			pii p = pp.second;
			int next_height = H[p.first][p.second] + 1;
			if (next_height == K + 1) {
				break;
			}
			for (pii loc : locations[next_height]) {
				if (d[loc.first][loc.second] > d[p.first][p.second] + dist (loc, p)) {
					if (s.count (make_pair (d[loc.first][loc.second], loc))) {
						s.erase (make_pair (d[loc.first][loc.second], loc));
					}
					d[loc.first][loc.second] = d[p.first][p.second] + dist (loc, p);
					s.insert (make_pair (d[loc.first][loc.second], loc));
				}
			}
		}
		printf ("%d\n", pp.first);
	}
	return 0;
}

