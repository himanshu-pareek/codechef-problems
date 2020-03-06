#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int sa, sb;
		cin >> sa >> sb;
		int a, b;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') a = i;
			else if (s[i] == 'B') b = i;
		}
		int diff = b - a;
		int add = sa + sb;
		bool safe = true;
		if (diff % add == 0) {
			int t = diff / add;
			if (t >= 0) {
				safe = false;
			}
		}
		if (safe) {
			cout << "safe" << endl;
		} else {
			cout << "unsafe" << endl;
		}
	}
	return 0;
}
