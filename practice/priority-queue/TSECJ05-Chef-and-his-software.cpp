#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int k, n, x;
    scanf ("%d %d", &k, &n);
    priority_queue < int, vector < int >, greater < int > > pq;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x);
        if (pq.size() < k) {
            pq.push (x);
        } else if (pq.top() < x) {
            pq.pop(); pq.push (x);
        }
        if (pq.size() < k) {
            printf ("-1 ");
        } else {
            printf ("%d ", pq.top());
        }
    }
    printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
