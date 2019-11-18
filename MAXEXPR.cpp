#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < double > k(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        double sum_k_c = 0.0, sum_inv_k = 0.0;
        for (int i = 0; i < n; i++) {
            sum_k_c += k[i] * c[i];
            sum_inv_k += 1.0 / k[i];
        }
        if (sum_k_c < 0.0) {
            cout << "-1" << endl;
            continue;
        }
        double F = sqrt (sum_k_c * sum_inv_k);
        cout << F;
        for (int i = 0; i < n; i++) {
            double x = (sum_k_c / (k[i] * k[i] * sum_inv_k)) - c[i];
            cout << " " << x;
        }
        cout << endl;
    }
}