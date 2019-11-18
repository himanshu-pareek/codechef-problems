#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector < int > A (N, -1);
		vector < int > C (M);
		int answer = 0;
		for (int & x : C) scanf ("%d", & x);
		for (int i = 0; i < M; i++) {
			int c = C[i];
			int index = -1;
			for (int j = 0; j < N; j++) {
				if (A[j] == c) {
					index = j;
					break;
				}
			}
			if (index != -1) {
				continue;
			}
			for (int j = 0; j < N; j++) {
				if (A[j] == -1) {
					index = j;
					break;
				}
			}
			if (index != -1) {
				A[index] = c;
				answer++;
				continue;
			}
			int max_ind = 0;
			for (int j = 0; j < N; j++) {
				int k = i + 1;
				for (; k < M; k++) {
					if (C[k] == A[j]) {
						break;
					}
				}
				if (k > max_ind) {
					max_ind = k;
					index = j;
				}
			}
			A[index] = c;
			answer++;
		}
		cout << answer << endl;
	}
	return 0;
}
