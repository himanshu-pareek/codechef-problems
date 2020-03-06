#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 1;

int gp[mx]; // greatest prime factor

void dfs (vector < pii > & factors, vector < int > & factors_sqr, int i = 0, ll x = 1) {
    if (i >= factors.size() || x * factors[i].first >= mx) {
        factors_sqr.push_back (x);
        return;
    }

    // multiply x by p^j 
    for (int j = 0; j <= 2 * factors[i].second && x < mx; x *= factors[i].first, j++) {
        dfs (factors, factors_sqr, i + 1, x);
    }
}

ll countGPPair (vector < int > & a, vector < int > & b, vector < int > & d) {
    vector < vector < int > > count (2, vector < int > (mx));
    for (int x : b) {
        count[0][x]++;
    }
    for (int x : d) {
        count[1][x]++;
    }
    ll answer = 0LL;
    for (int element : a) {
        int x = element;
        // prime factorize x
        vector < pii > factors;
        while (x > 1) {
            int p = gp[x], c = 0;
            while (x % p == 0) {
                c++; x /= p;
            }
            factors.push_back (make_pair (p, c));
        }

        // factors is in decreasing order
        reverse (factors.begin(), factors.end());
        // Generate factors of x^2 < mx
        vector < int > factors_sqr;
        dfs (factors, factors_sqr);

        /**
         * cout << "factors of " << (element * element) << ": ";
        for (int y : factors_sqr) {
            cout << y << ", ";
        }
        cout << endl; */

        for (int fact : factors_sqr) {
            ll val = (ll)element * element / fact;
            if (val < mx) {
                answer += (ll) count[0][fact] * count[1][val];
            }
        }
    }
    // cout << "answer = " << answer << endl;
    return answer;
}

void solve () {
    int n, m, x;
    scanf ("%d %d", &n, &m);
    vector < int > posX, posY, negX, negY;
    bool zeroPresent = false;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x);
        if (x < 0) {
            negX.push_back (-x);
        } else if (x > 0) {
            posX.push_back (x);
        } else {
            zeroPresent = true;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf ("%d", &x);
        if (x < 0) {
            negY.push_back (-x);
        } else if (x > 0) {
            posY.push_back (x);
        } else {
            zeroPresent = true;
        }
    }

    ll answer = 0LL;
    n = posX.size() + negX.size();
    m = posY.size() + negY.size();
    // cout << n << " " << m << endl;
    if (zeroPresent) {
        answer = (ll) m * n;
        // cout << "Initial answer = " << answer << endl;
    }
    answer += countGPPair (posX, posY, negY);
    answer += countGPPair (negX, posY, negY);
    answer += countGPPair (posY, posX, negX);
    answer += countGPPair (negY, posX, negX);

    printf ("%lld\n", answer);
}

int main() {
    // calculate greatest prime factor using seive method
    for (int i = 2; i < mx; i++) {
        if (!gp[i]) {
            for (int j = i; j < mx; j += i) {
                gp[j] = i;
            }
        }
    }
    /**
    for (int i = 0; i < 10; i++) {
        cout << "gp[" << i << "] = " << gp[i] << endl;
    } */

    int t;
    scanf ("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}

