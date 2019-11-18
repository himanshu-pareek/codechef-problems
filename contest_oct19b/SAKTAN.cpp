#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void printVector (const vector < pair < int, int > > &vec) {
    for (const pair < int, int > p : vec) {
        cout << p.first << ", " << p.second << endl;
    }
    cout << endl << endl;
}

int getRandomInt (int a, int b) {
    return a + (rand() % (b - a + 1));
}

ll solve1 (int N, int M, vector < pair < int, int > > &vec) {
    vector < int > rows (N, 0);
    vector < int > cols (M, 0);
    for (const pair < int, int > p : vec) {
        rows[p.first - 1] = 1 - rows[p.first - 1];
        cols[p.second - 1] = 1 - cols[p.second - 1];
    }
    int zero_rows = 0, zero_cols = 0;
    for (const int x : rows) {
        zero_rows += (x == 0);
    }
    for (const int y : cols) {
        zero_cols += (y == 0);
    }
    return (ll)zero_rows * (M - zero_cols) + (ll)zero_cols * (N - zero_rows);
}

ll solve2 (int N, int M, vector < pair < int, int > > &vec) {
    vector < vector < int > > matrix (N, vector < int > (M, 0));
    for (const pair < int, int > p : vec) {
        int row = p.first - 1, col = p.second - 1;
        for (int i = 0; i < N; i++) {
            matrix[i][col]++;
        }
        for (int j = 0; j < M; j++) {
            matrix[row][j]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = ans + (matrix[i][j] % 2);
        }
    }
    return ans;
}

int main() {
    int T, N, M, Q;
    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        // N = getRandomInt (1, 100);
        // M = getRandomInt (1, 100);
        // Q = getRandomInt (1, 100);
        vector < pair < int, int > > operations (Q);
        for (int i = 0; i < Q; i++) {
            cin >> operations[i].first >> operations[i].second;
            // operations[i].first = getRandomInt (1, N);
            // operations[i].second = getRandomInt (1, M);
        }
        ll ans = solve1 (N, M, operations);
        // ll ans2 = solve2 (N, M, operations);
        // cout << ans1 << " == " << ans2 << endl;
        // if (ans1 != ans2) {
        //     cout << "FAILED" << endl;
        //     printVector (operations);
        //     break;
        // } else {
        //     cout << "SUCCESS" << endl;
        // }
        cout << ans << endl;
    }
    return 0;
}
