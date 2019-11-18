#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

bool abcomp (const pair < ll, ll > &a, const pair < ll, ll > &b) {
    return a.second > b.second;
}

void printVector (vector < ll > &vec) {
    for (ll x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector < pair < ll, ll > > ab (N);
        for (int i = 0; i < N; i++) {
            cin >> ab[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> ab[i].second;
        }
        vector < ll > dp (N + 1, 0);
        sort (ab.begin(), ab.end(), abcomp);
        // dp[0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j >= 0; j--) {
                dp[j + 1] = max (dp[j + 1], dp[j] + (ab[i].first + j * ab[i].second));
            }
            // printVector (dp);
        }
        for (int i = 1; i <= N; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}