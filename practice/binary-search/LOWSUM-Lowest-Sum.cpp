#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 20005;

ll a[mx], b[mx];

struct comparePair {
	bool operator () (pii const & p1, pii const & p2) {
		if (a[p1.first] + b[p1.second] == a[p2.first] + b[p2.second]) {
			if (p1.first == p2.first) {
				return p1.second < p2.second;
			}
			return p1.first < p2.first;
		}
		return a[p1.first] + b[p1.second] < a[p2.first] + b[p2.second];
	}
};

template < typename T >
void max_self (T & a, T b) {
	if (a < b) a = b;
}

template < typename T >
void printVector (const vector < T > & vec) {
	for (const T t : vec) {
		cout << t << " ";
	}
	cout << endl;
}

void solve() {
	int k, q, n;
	scanf ("%d %d", &k, &q);
	// vector < ll > a (k), b(k);
	for (int i = 0; i < k; i++) {
		scanf ("%lld", a + i);
	}
	for (int i = 0; i < k; i++) {
		scanf ("%lld", b + i);
	}
	sort (a, a + k);
	sort (b, b + k);
	set < pii, comparePair > pq;
	vector < int > queries (q);
	int max_q = 0;
	for (int & x : queries) {
		scanf ("%d", & x);
		max_self (max_q, x);
	}
	vector < ll > ans (max_q + 1);
	pii p = make_pair (0, 0);
	pq.insert (p);
	for (int i = 1; i <= max_q; i++) {
		p = *pq.begin(); pq.erase(p);
		ans[i] = a[p.first] + b[p.second];
		//cout << p.first << " " << p.second << " " << ans[i] << endl;
		if (p.first < k - 1) {
			pq.insert (make_pair (p.first + 1, p.second));
		}
		if (p.second < k - 1) {
			pq.insert (make_pair (p.first, p.second + 1));
		}
	}
	for (int i = 0; i < q; i++) {
		printf ("%lld\n", ans[queries[i]]);
	}
	//for (int i = 1; i <= max_q; i++) {
		//printf ("%lld\n", ans[i]);
	//}
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

		
