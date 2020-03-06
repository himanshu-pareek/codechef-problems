#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		vector < int > count (105);
		for (int i = 0; i < n; i++) {
			cin >> x;
			count[x]++;
		}
		int maxCount = 0;
		for (int x : count) {
			maxCount = max (maxCount, x);
		}
		cout << n - maxCount << endl;
	}
	return 0;
}
