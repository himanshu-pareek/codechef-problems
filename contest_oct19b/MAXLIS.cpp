#include <iostream>
#include <vector>

using namespace std;

int findIndex (const vector < int > & T, const vector < int > & a, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[T[mid]] >= x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int lis (const vector < int > & a) {
    const int n = a.size();
    if (n == 0) return 0;
    vector < int > T (n + 1);
    // vector < int > P (n, -1);
    T[0] = -1, T[1] = 0;
    int len = 1;
    for (int i = 1; i < n; i++) {
        int index = findIndex (T, a, 1, len, a[i]);
        T[index] = i;
        // P[T[index]] = T[index] - 1;
        len = max (len, index);
    }
    return len;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector < int > A (N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= (K - 1) / 2; i++) {
        cout << i << " ";
    }
    for (int x : A) {
        if (x > (K - 1) / 2) {
            cout << x << " ";
        }
    }
    cout << endl;
    return 0;
}
