#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector < int > vec (N + 5);
        for (int i = 0; i < 5; i++) vec[i] = INT_MAX;
        for (int i = 5; i < N + 5; i++) {
            cin >> vec[i];
        }
        int ans = 0;
        for (int i = 5; i < N + 5; i++) {
            bool isValid = true;
            for (int j = i - 5; j < i; j++) {
                if (vec[i] >= vec[j]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}