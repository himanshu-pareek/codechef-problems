#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve () {
	int n, choice, x;
	scanf ("%d", &n);
	priority_queue < int > maxpq;
	priority_queue < int, vector < int >, greater < int > > minpq;
	while (n--) {
		scanf ("%d", &choice);
		if (choice == 1) {
			scanf ("%d", & x);
			//cout << choice << " " << x << endl;
			maxpq.push (x);
		} else {
			//cout << choice << endl;
			int num = minpq.size() + maxpq.size();
			int toAdd = num/3 - minpq.size();
			while (toAdd--) {
				int y = maxpq.top();
				//cout << "-- " << x << "--" << endl;
				minpq.push (y);
				maxpq.pop();
			}
			while (!minpq.empty()) {
				if (minpq.top() >= maxpq.top()) {
					break;
				}
				int y = minpq.top();
				int z = maxpq.top();
				minpq.pop(); maxpq.pop();
				minpq.push (z); maxpq.push (y);
			}
			if (minpq.empty()) {
				printf ("No reviews yet\n");
			} else {
				printf ("%d\n", minpq.top());
			}
		}
	}
}

int main() {
	int t;
	//scanf ("%d", &t);
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
