#include <bits/stdc++.h>

#define MOD 1000000007

#define ll long long
#define int ll

int num[100005][10][2];
int sum[100005][10][2];
int powers[1 << 17];

using namespace std;

void add (int &x, int y) {
    x += y;
    if (x > MOD) x -= MOD;
}



pair < int, int > solve(int n, string s) {
    vector < int > vec;
    for (char c : s) {
        vec.push_back (c - '0');
    }

    for (int index = 0; index <= vec.size(); index++) {
        for (int digit = 0; digit < 10; digit++) {
            for (int equal = 0; equal < 2; equal++) {
                num[index][digit][equal] = sum[index][digit][equal] = 0;
            }
        }
    }

    num[0][0][1] = 1;
    for (int index = 0; index <= vec.size(); index++) {
        for (int digit = 0; digit < 10; digit++) {
            for (int equal = 0; equal < 2; equal++) {
                int next_index = index + 1;
                for (int next_digit = 0; next_digit < 10; next_digit++) {
                    if (equal && (next_digit > vec[index]))
                        break;
                    int equal_next = equal && (vec[index] == next_digit);
                    add (num[next_index][next_digit][equal_next], num[index][digit][equal]);
                    add (sum[next_index][next_digit][equal_next], sum[index][digit][equal]);
                    if (next_digit != digit) {
                        add (sum[next_index][next_digit][equal_next],
                             (((num[index][digit][equal] * powers[vec.size() - index - 1]) % MOD)
                                    * next_digit ) % MOD );

                    }
                }
            }
        }
    }

    pair < int, int > ans = {0, 0};
    for (int digit = 0; digit < 10; digit++) {
        ans.first = (ans.first + sum[vec.size()][digit][0]) % MOD;
        ans.second = (((ans.second + sum[vec.size()][digit][0] % MOD) + sum[vec.size()][digit][1])) % MOD;
    }

    return ans;
}

int32_t main () {
    powers[0] = 1;
    for (int i = 1; i <= 100005; i++) {
        powers[i] = (powers[i - 1] * 10) % MOD;
    }
    int T;
    cin >> T;
    while (T--) {
        int nl, nr;
        string l, r;
        cin >> nl >> l;
        cin >> nr >> r;
        cout << (MOD + solve(nr, r).second - solve(nl, l).first) % MOD << endl;
    }
}