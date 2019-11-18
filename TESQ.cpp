#include <iostream>
#include <vector>
#include <climits>

#define ll long long

#define MOD 1000000007
#define MAXW 100005
#define MAXN 100005

using namespace std;

int combination[MAXW][MAXN];

void make_combinations() {
    for (int i = 0; i < MAXN; i++) {
        combination[0][i] = 0;
    }
    for (int i = 0; i < MAXW; i++) {
        combination[i][0] = 1;
    }
    for (int i = 0; i < MAXW; i++) {
        for (int j = 0; j < MAXN; j++) {
            combination[i][j] = (combination[i][j - 1] + combination[i - 1][j - 1] % MOD);
        }
    }
}

void printMatrix (vector < vector < int > > &matrix) {
    for (vector < int > vec : matrix) {
        for (int x : vec) {
            cout << x << "\t";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;
}

vector < int > dfs (vector < vector < int > > &g, int s, int parent, vector < vector < int > > &mat) {
    vector < int > to_return;
    for (int i = 0; i < mat[0].size(); i++) {
        mat[s][i] = parent;
    }
    mat[s][s] = s;
    to_return.push_back (s);
    for (int u : g[s]) {
        if (u != parent && u != s) {
            vector < int > temp = dfs (g, u, s, mat);
            for (int v : temp) {
                mat[s][v] = temp[0];
                to_return.push_back (v);
            }
        }
    }
    return to_return;
}

int getNumIncreasingNumbers (int start, int end, int count) {
    if (count > end - start + 1) {
        return 0;
    }

    return 0;
}

int getNumNDNumbers (int start, int end, int count) {

    return 0;
}

int main() {
    int t;
    t = 1;
    make_combinations();
    cout << "combinations formed" << endl;
    while (t--) {
        int n, q, u, v;
        cin >> n >> q;
        vector < int > w (n + 1);
        vector < vector < int > > g (n + 1);
        ll maxw = INT_MIN;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            maxw = max (maxw, (ll)w[i]);
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            g[u].push_back (v);
            g[v].push_back (u);
        }
        int s = -1;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() == 1) {
                s = i;
                break;
            }
        }
        // cout << "Source: " << s << endl;
        vector < vector < int > > mat (n + 1, vector < int > (n + 1, 0));
        dfs (g, s, s, mat);
        // printMatrix (mat);
        while (q--) {
            string query_str;
            cin >> query_str;
            if (query_str == "UPDATE") {
                cin >> u >> v;
                w[u] = v;
            } else if (query_str == "INCREASING") {
                int a, b;
                cin >> u >> v >> a >> b;
                int curr = u;
                int methods = 1;
                int count = 0;
                int start = a;
                if (w[u] == -1) {
                    count++;
                } else {
                    count = 0;
                    start = w[u] + 1;
                }
                while (curr != v) {
                    u = mat[curr][v];
                    if (w[u] == -1) {
                        count++;
                    } else {
                        int x = getNumIncreasingNumbers (start, w[u] - 1, count);
                        methods = (methods * x) % MOD;
                        count = 0;
                        start = w[u] + 1;
                    }
                    curr = u;
                }
                if (w[v] == -1) {
                    int x = getNumIncreasingNumbers (start, b, count);
                    methods = (methods * x) % MOD;
                }
                cout << methods << endl;
            } else if (query_str == "DECREASING") {
                int a, b;
                cin >> v >> u >> b >> a;
                int curr = u;
                int methods = 1;
                int count = 0;
                int start = a;
                if (w[u] == -1) {
                    count++;
                } else {
                    count = 0;
                    start = w[u] + 1;
                }
                while (curr != v) {
                    u = mat[curr][v];
                    if (w[u] == -1) {
                        count++;
                    } else {
                        int x = getNumIncreasingNumbers (start, w[u] - 1, count);
                        methods = (methods * x) % MOD;
                        count = 0;
                        start = w[u] + 1;
                    }
                    curr = u;
                }
                if (w[v] == -1) {
                    int x = getNumIncreasingNumbers (start, b, count);
                    methods = (methods * x) % MOD;
                }
                cout << methods << endl;
            } else if (query_str == "NON-DECREASING") {
                int a, b;
                cin >> u >> v >> a >> b;
                int curr = u;
                int methods = 1;
                int count = 0;
                int start = a;
                if (w[u] == -1) {
                    count++;
                } else {
                    count = 0;
                    start = w[u] + 1;
                }
                while (curr != v) {
                    u = mat[curr][v];
                    if (w[u] == -1) {
                        count++;
                    } else {
                        int x = getNumNDNumbers (start, w[u] - 1, count);
                        methods = (methods * x) % MOD;
                        count = 0;
                        start = w[u] + 1;
                    }
                    curr = u;
                }
                if (w[v] == -1) {
                    int x = getNumNDNumbers (start, b, count);
                    methods = (methods * x) % MOD;
                }
                cout << methods << endl;
            } else if (query_str == "NON-INCREASING") {
                int a, b;
                cin >> v >> u >> b >> a;
                int curr = u;
                int methods = 1;
                int count = 0;
                int start = a;
                if (w[u] == -1) {
                    count++;
                } else {
                    count = 0;
                    start = w[u] + 1;
                }
                while (curr != v) {
                    u = mat[curr][v];
                    if (w[u] == -1) {
                        count++;
                    } else {
                        int x = getNumNDNumbers (start, w[u] - 1, count);
                        methods = (methods * x) % MOD;
                        count = 0;
                        start = w[u] + 1;
                    }
                    curr = u;
                }
                if (w[v] == -1) {
                    int x = getNumNDNumbers (start, b, count);
                    methods = (methods * x) % MOD;
                }
                cout << methods << endl;
            }
        }
    }
    return (int)0;
}
