#include <iostream>
#include <vector>

using namespace std;

int getRandomNumber (int a, int b) {
	return a + (rand() % (b - a + 1));
}

string getRandomString (int k) {
	int n = getRandomNumber (1, 100);
	string ans = "";
	for (int i = 0; i < n; i++) {
		int x = getRandomNumber (0, 3 * k);
		if (x >= k) ans += '?';
		else ans += (x + '0');
	}
	return ans;
}

string solve (int k, string t) {
	string s;
	for (char c : t) s += c;
	// cout << s << endl;
	const int n = (int) s.size();
	if (n == 1 && s[0] != '?') return s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '?' && s[i] == s[(i + 1) % n]) {
			return "NO";
		}
	}
	if (k == 2) {
		//cout << "k = " << k << endl;
		if (n > 2 && (n % 2)) {
			return "NO";
		}
		string s1 = "0", s2 = "1";
		// s1[0] = '0'; s2[0] = '1';
		for (int i = 1; i < n; i++) {
			s2 += s1[i - 1];
			s1 += s2[i - 1];
		}
		//cout << s1 << endl << s2 << endl;
		bool matched = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != '?' && s[i] != s1[i]) {
				matched = false;
				break;
			}
		}
		if (matched) return s1;
		matched = true;
		for (int i = 0; i < n; i++) {
			if (s[i] != '?' && s[i] != s2[i]) {
				matched = false;
				break;
			}
		}
		if (matched) return s2;
		return "NO";
	}

	vector < char > available_colors;
	for (int i = 0; i < k; i++) {
		available_colors.push_back (i + '0');
	}
	for (int i = 0; i < n; i++)  {
		if (s[i] != '?') continue;
		char prev = s[(i - 1 + n) % n];
		char next = s[(i + 1) % n];
		for (char c : available_colors) {
			if (c != prev && c != next) {
				s[i] = c; break;
			}
		}
		if (s[i] == '?') {
			return "NO";
		}
	}
	return s;
}

string solve2 (int k, string s) {
	int n = s.length();

	string ans = "NO";
	for (char c = '0'; c < '0' + k; ++c) {
		string w = s;
		if (w[0] != '?' && w[0] != c) {
			continue;
		}

		bool good = true;
		w[0] = c;
		for (int i = 1; i < n; ++i) {
			bool ok = false;
			for (char d = '0'; d < '0' + k; ++ d) {
				if (w[i] != '?' && w[i] != d) {
					continue;
				}
				if (d != w[i - 1] && d != w[(i + 1) % n]) {
					w[i] = d;
					ok = true;
					break;
				}
			}
			if (!ok) {
				good = false;
				break;
			}
		}
		if (good) {
			ans = w;
			break;
		}
	}
	return ans;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int k;
		string s;
		cin >> k >> s;
		// k = getRandomNumber (1, 10);
		// k = 1;
		// s = getRandomString (k);
		// s = "1";
		string my_ans = solve(k, s);
		// string ed_ans = solve2 (k, s);
		//cout << "k = " << k << ", s = " << s << endl;
		//cout << "my_ans = " << my_ans << endl;
		//cout << "ed_ans = " << ed_ans << endl;
		//if (my_ans != ed_ans) {
			//cout << "FAILURE" << endl;
			//break;
		//}
		//cout << "SUCCESS" << endl;
		cout << my_ans << endl;
	}
	return 0;
}
