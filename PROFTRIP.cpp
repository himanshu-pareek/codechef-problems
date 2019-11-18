#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        ll w[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                w[i][j] = 1000000000;
            }
        }
        int u, v;
        while (r--) {
            cin >> u >> v;
            cin >> w[u][v];
            w[v][u] = w[u][v];
        }
        ll F[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> F[i];
        }
        int P, Q;
        cin >> P >> Q;
        for (int i = 1; i <= n; i++) {
            w[i][i] = 0;
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << w[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "------------------------" << endl;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (w[i][k] + w[k][j] < w[i][j]) {
                        w[i][j] = w[i][k] + w[k][j];
                    }
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << w[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "------------------------" << endl;
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (u == v) {
                    w[u][v] = 0;
                } else {
                    w[u][v] *= F[u];
                    // w[v][u] *= F[v];
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << w[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "------------------------" << endl;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (w[i][k] + w[k][j] < w[i][j]) {
                        w[i][j] = w[i][k] + w[k][j];
                    }
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << w[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "------------------------" << endl;
        cout << w[P][Q] << endl;
    }
	return 0;
}
