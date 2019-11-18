#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve1 (string s) {
    int n = s.length();
    int i = 0;
    while (i < n && s[i] == '0') {
        i++;
    }
    s = s.substr (i);
    n = s.size();
    if (!n) { s = "0"; n = 1; };

    bool flag = true;
    for (char c : s) {
        if (c != '9') {
            flag = false;
            break;
        }
    }
    if (flag) {
        for (int i = 0; i < n; i++) s[i] = '0';
        s += "0";
        s[0] = s[n] = '1';
        return s;
    }

    int l = 0, r = n - 1;
    bool changed = false;
    while (l < r) {
        if (s[l] > s[r]) {
            changed = true;
        } else if (s[l] < s[r]) {
            changed = false;
        }
        s[r] = s[l];
        l++, r--;
    }
    if (l != r) {
        l--, r++;
    }
    if (!changed) {
        while (s[l] == '9') {
            s[l--] = s[r++] = '0';
        }
        s[l]++;
        s[r] = s[l];
    }
    return s;
}

bool ispal (ll n) {
    ll m = n;
    ll s = 0;
    while (n) {
        s *= 10;
        s += n % 10;
        n /= 10;
    }
    return m == s;
}

string solve2 (string s) {
    ll num = atoll (&s[0]);
    num++;
    while (true) {
        if (ispal (num)) {
            break;
        }
        num++;
    }
    return to_string (num);
}

string generateRandomString() {
    int n = rand() % 16;
    string s = "";
    for (int i = 0; i < n; i++) {
        int x = rand() % 10;
        s += (x + '0');
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // string s = generateRandomString ();
        // cout << "s = " << s << endl;
        // string ans1 = solve1 (s);
        // string ans2 = solve2 (s);
        // cout << "ans1 = " << ans1 << endl;
        // cout << "ans2 = " << ans2 << endl;
        // if (ans1 != ans2) {
        //     cout << "MISMATCH" << endl;
        //     exit(0);
        // }
        // cout << "-------------------------------" << endl;
        string s;
        cin >> s;
        cout << solve1 (s) << endl;
    }
	return 0;
}
