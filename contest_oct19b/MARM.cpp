#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getRandomInt (int a, int b) {
    return a + (rand() % (b - a + 1));
}

void printVector (const vector < int > &vec) {
    for (const int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

bool areEqual (const vector < int > &vec1, const vector < int > &vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        if (vec1[i] != vec2[i])
            return false;
    }
    return true;
}

void solve1 (int N, ll K, vector < int >& A) {
    // vector < int > ans (N);
    // for (int i = 0; i < N; i++) {
    //     ans[i] = A[i];
    // }
    for (int i = 0; i < K; i++) {
        int a = A[i % N], b = A[N - (i % N) - 1];
        A[i % N] = a ^ b;
    }
}

void solve2 (int N, ll K, vector < int > &A) {
    if (N % 2 && K >= (N + 1) / 2) {
        A[N / 2] = 0;
    }
    K %= (3 * N);
    solve1 (N, K, A);
}

int main() {
    int T, N;
    ll K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        // N = getRandomInt (1, 10000);
        // K = (ll) getRandomInt (3 * N, 1000000000);
        // K %= (3 * N);
        vector < int > A (N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            // A[i] = getRandomInt (1, 10000000);
        }
        // for (int i = 0; i < K; i++) {
        //     int a = A[i % N], b = A[N - (i % N) - 1];
        //     A[i % N] = a ^ b;
        // }
        // for (int i = 0; i < N; i++) {
        //     cout << A[i] << " ";
        // }
        // vector < int > ans1 = solve1 (N, K, A);
        solve2 (N, K, A);
        // if (areEqual (ans1, ans2)) {
        //     cout << "SUCCESS for N = " << N << " and K = " << K << endl;
        // } else {
        //     cout << "ERROR for N = " << N << " and K = " << K << endl;
        //     printVector (A);
        //     printVector (ans1);
        //     printVector (ans2);
        //     break;
        // }
        printVector (A);
        // cout << endl;
    }
    return 0;
}
