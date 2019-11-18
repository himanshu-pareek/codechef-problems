#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int u, v, n;
        cin >> n >> u >> v;
        vector < int > pu;
        vector < int > pv;
        int node = u;
        while (node >= 1) {
            pu.push_back (node);
            node /= 2;
        }
        node = v;
        while (node >= 1) {
            pv.push_back (node);
            node /= 2;
        }
        int i = pu.size() - 1, j = pv.size() - 1;
        while (i >= 0 && j >= 0 && pu[i] == pv[j]) {
            i--; j--;
        }
        i++; j++;
        int a = 1, b = 0;
        if (u < v) {
            for (int k = j; k >= 1; k--) {
                a = a << 1;
                b = b << 1;
                if (2 * pv[k] + 1 == pv[k - 1]) {
                    b++;
                }
            }
        } else {
            for (int k = i; k >= 1; k--) {
                a = a << 1;
                b = b << 1;
                if (2 * pu[k] + 1 == pu[k - 1]) {
                    b++;
                }
            }
        }
        /**
         * ax + b <= n
         * ax <= (n - b)
         * x <= (n - b) / a
         */
        int x = (n - b) / a;
        cout << x << endl;
    }
}