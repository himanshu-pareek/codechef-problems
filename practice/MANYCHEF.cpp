#include <iostream>
#include <algorithm>
using namespace std;

bool isValidChef (string & s, int i) {
	string chef = "FEHC";
	for (int j = i; j < i + 4; j++) {
		if (s[j] != '?' && s[j] != chef[j - i]) {
			return false;
		}
	}
	return true;
}

void solve () {
	string s;
	cin >> s;
	reverse (s.begin(), s.end());
	for (int i = 0; i < (int) s.size() - 3; i++) {
		// if (s[i] != '?') continue;
		//cout << "i = " << i << endl;
		if (isValidChef (s, i)) {
			s[i] = 'F', s[i + 1] = 'E', s[i + 2] = 'H', s[i + 3] = 'C';
			i += 3;
		} else if (s[i] == '?') {
			s[i] = 'A';
		}
	}
	//cout << s << endl;
	for (int i = (int) s.size() - 3; i < (int) s.size(); i++) {
		if (s[i] == '?') {
			s[i] = 'A';
		}
	}
	reverse (s.begin(), s.end());
	cout << s << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
