#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void solve(string s) {
	if (s.size() == 0) return;
	bool str = false, flt = false;
	for (char c : s) {
		if (c >= 'a' && c <= 'z') {
			str = true;
		} else if (c == '.') {
			flt = true;
		}
	}
	if (str) {
		printf ("string");
	} else if (flt) {
		printf ("float");
	} else {
		printf ("int");
	}
}

int main() {
	string s;
	char c;
	while (scanf ("%c", &c) > 0) {
		if (c == ' ' || c == '\n') {
			solve (s);
			printf ("%c", c);
			s = "";
		} else {
			s += c;
		}
	}
	return 0;
}
