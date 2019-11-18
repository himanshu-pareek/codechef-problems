#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string removeSpaces (string s) {
    string t = "";
    for (char c : s) {
        if (c != ' ' && c != '\t') {
            t += c;
        }
    }
    return t;
}

void solve () {
    int k; string s;
    scanf ("%d ", &k);
    getline (cin, s);
    s = removeSpaces (s);
    k %= 26;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - 'A';
        d = (d - k + 26) % 26;
        s[i] = d + 'A';
    }
    string t;
    for (int i = 0; i < (int) s.size(); i++) {
        if (i < (int) s.size() - 1 && s[i] == 'Q' && s[i + 1] == 'Q') {
            t += ' ';
            i++;
        } else {
            t += s[i];
        }
    }
    cout << t << endl;
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve ();
    }
    return 0;
}
