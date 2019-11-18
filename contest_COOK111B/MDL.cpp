#include <iostream>
#include <climits>

using namespace std;

int min (int a, int b) {
	return a < b ? a : b;
}

int max (int a, int b) {
	return a > b ? a : b;
}

int main() {
	int T, N, first, last;
	cin >> T;
	while (T--) {
		cin >> N;
		int A[N];
		for (int i = 0; i < N; i++) cin >> A[i];
		first = INT_MAX, last = INT_MIN;
		for (int i = 0; i < N; i++) {
			first = min (first, A[i]); last = max (last, A[i]);
		}
		for (int i = 0; i < N; i++) {
			if (A[i] == first) {
				cout << first << " " << last << endl; break;
			}
			if (A[i] == last) {
				cout << last << " " << first << endl; break;
			}
		}
	}
	return 0;
}
