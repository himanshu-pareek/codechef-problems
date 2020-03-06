#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		string c;
		int na = (int) a.size();
		int nb = (int) b.size();
		if (b == "0") {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < abs (na - nb); i++) {
			c += '0';
		}
		if (na < nb) {
			a = c + a;
			na = nb;
		} else {
			b = c + b;
			nb = na;
		}
		//cout << "a = " << a << endl << "b = " << b << endl;
		int ans = 0;
		int sum = 0;
		int i = na - 1;
		while (i >= 0) {
			int count1 = (a[i] == '1') + (b[i] == '1');
			if (count1 != 2) {
				i--;
			} else {
				sum = 1;
				i--;
				while (i >= 0) {
					count1 = (a[i] == '1') + (b[i] == '1');
					if (count1 == 1) {
						sum++;
					} else {
						break;
					}
					i--;
				}
				ans = max (ans, sum);
			}
		}
		cout << (ans + 1) << endl;
	}
	return 0;
}
