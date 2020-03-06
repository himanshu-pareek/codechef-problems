#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		n = 26;
		vector < vector < int > > positions (n);
		for (int i = 0; i < (int) s.size(); i++) {
			positions[s[i] - 'a'].push_back (i);
		}
		int diff = (int) s.size();
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < (int) positions[i].size(); j++) {
				diff = min (diff, positions[i][j] - positions[i][j - 1]);
			}
		}
		cout << (s.size() - diff) << endl;
	}
	return 0;
}

