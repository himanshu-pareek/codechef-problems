#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solveBruteForce (string s) {
    ll ans = 0;
    int n = s.size();
    int counta[n + 1], countb[n + 1], countc[n + 1];
    counta[0] = countb[0] = countc[0] = 0;
    for (int i = 0; i < n; i++) {
        counta[i + 1] = counta[i] + (s[i] == 'A');
        countb[i + 1] = countb[i] + (s[i] == 'B');
        countc[i + 1] = countc[i] + (s[i] == 'C');
        // cout << counta[i + 1] << " " << countb[i + 1] << " " << countc[i + 1] << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (((counta[j + 1] - counta[i]) == (countb[j + 1] - countb[i])) && ((counta[j + 1] - counta[i]) == (countc[j + 1] - countc[i]))) {
                ans++;
            }
        }
    }
    return ans;
}

string getRandomString() {
    // return "ABACABA";
    int n = rand() % 1000;
    string s;
    while (n--) {
        int x = rand() % 3;
        if (x == 0) {
            s += 'A';
        } else if (x == 1) {
            s += 'B';
        } else {
            s += 'C';
        }
    }
    return s;
}

int main() {
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        string s;
        cin >> s;
        // s = getRandomString();
        ll n = s.size();
        unordered_map < ll , ll > m;
        m[0] = 1;
        ll counta = 0, countb = 0, countc = 0;
        ll ans = 0;
        for (char c : s) {
            if (c == 'A')
                counta++;
            else if (c == 'B')
                countb++;
            else
                countc++;

            ll countab = countb - counta;
            ll countbc = countc - countb;

            ll num = countab * (n + 1) + countbc;
            if (m.find(num) != m.end()) {
                ans += m[num];
                m[num]++;
            } else {
                m[num] = 1;
            }
        }
        // ll ans2 = solveBruteForce (s);
        // cout << "s = " << s << endl;
        // cout << "ans1 = " << ans << endl;
        // cout << "ans2 = " << ans2 << endl;
        // if (ans == ans2) {
        //     cout << "SUCCESS" << endl;
        // } else {
        //     cout << "FAILED" << endl;
        //     break;
        // }
        cout << ans << endl;
    }
    return 0;
}