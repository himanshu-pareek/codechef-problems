#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template < typename T>
void printVector (const vector < T > & vec) {
    for (const T x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
void printMatrix (const vector < vector < T > > & matrix) {
    for (const vector < T > vec : matrix) {
        printVector (vec);
    }
    cout << endl;
}

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector < int > A (N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        
        // Construct R[i, j]
        vector < vector < int > > R (N + 1, vector < int > (N + 1));
        for (int i = 1; i <= N; i++) {
            vector < int > frequency (1001, 0);
            int maxFrequency = 0, maxFreqIndex = -1;
            for (int j = i; j <= N; j++) {
                frequency[A[j]]++;
                if (frequency[A[j]] > maxFrequency) {
                    maxFrequency = frequency[A[j]];
                    maxFreqIndex = j;
                }
                R[i][j] = (j - i + 1) - maxFrequency;
            }
        }

        // printMatrix (R);
        
        // Construct F[x, k]
        // F[x, k] = min (F[i, k - 1] + R[i + 1, x]) for all 1 <= i <= x - 1
        // F[x, 0] = R[1, x] for all 1 <= x <= N
        vector < vector < int > > F (N + 1, vector < int > (K + 1, INT_MAX));
        for (int k = 0; k <= K; k++) {
            F[1][k] = 0;
        }
        for (int x = 1; x <= N; x++) {
            F[x][0] = R[1][x];
            for (int k = 1; k <= K; k++) {
                for (int i = 1; i < x; i++) {
                    F[x][k] = min (F[x][k], F[i][k - 1] + R[i + 1][x]);
                }
            }
        }

        // printMatrix (F);
        
        cout << F[N][K] << endl;
        
    }
    return 0;
}