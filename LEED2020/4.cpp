#include <bits/stdc++.h>
using namespace std;

void solve () {
	string s;
	cin >> s;
	int n = 1;
	string temp = "TEMP";
	stack < string > st;
	for (char c : s) {
		if (c != '+' && c != '-' && c != '*' && c != '/') {
			st.push (string (1, c));
		} else {
			string op;
			if (c == '+') op = "AD";
			else if (c == '-') op = "SB";
			else if (c == '*') op = "ML";
			else op = "DV";
			string b = st.top(); st.pop();
			string a = st.top(); st.pop();
			cout << "LD " << a << endl;
			cout << op << " " << b << endl;
			string src = temp + to_string (n++);
			cout << "ST " << src << endl;
			st.push (src);
		}
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
