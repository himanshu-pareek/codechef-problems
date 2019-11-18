#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)

string myfunction (string s) {
    int n = s.length();
    int counta = 0, countb = 0;
    for (char c : s) {
        if (counta > 2 && countb > 2) {
            break;
        }
        if (c == 'A') {
            counta++;
        } else {
            countb++;
        }
    }
    if (counta == 2) {
        return "A";
    }
    if (countb == 2) {
        return "B";
    }
    if (n < 4) {
        return "-1";
    }
    int index = -1;
    s = '.' + s + '.';
    for (int i = 1;i < n; i++) {
        if (s[i] != s[i - 1] && s[i] == s[i + 1] && s[i] != s[i + 2]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return "-1";
    } else {
        string ans;
        for (int i = 1; i <= n; i++) {
            if (i != index) {
                ans += s[i];
            }
        }
        return ans;
    }
    return "-1";
}

string generateRandomString() {
    int n = rand() % 10 + 1;
    string s = "";
    for (int i = 0; i < n; i++) {
        int x = rand() % 111;
        if (x < 50) {
            s += "A";
        } else {
            s += "B";
        }
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string ans = myfunction (s);
        cout << ans << endl;
    }
	return 0;
}
