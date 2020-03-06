#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int num = 4;
		if (n > 1 && !(n & 1)) {
			num = 5;
		}
		cout << num << endl;
		for (int x : {0, n}) {
			for (int y : {0, n}) {
				cout << x << " " << y << endl;
			}
		}
		if (num == 5) {
			cout << n/2 << " " << n/2 << endl;
		}
	}
	return 0;
}
