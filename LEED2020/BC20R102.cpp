#include <bits/stdc++.h>
using namespace std;

const int mx = 105;

void solve () {
	int N, K, id;
	char M;
	scanf ("%d %d", &N, &K);
	vector < int > A (N);
	vector < int > C (mx);
	int size = 0;
	while (K--) {
		cin >> M >> id;
		if (M == 'A') {
			// arrival
			if (size < N) {
				printf ("AVAILABLE\n");
				A[size++] = id;
				C[id] = 0;
			} else {
				printf ("NO ROOM");
				continue;
			}
		} else {
			// departure
			// find position of the car with id = id
			int index = -1;
			for (int i = 0; i < size; i++) {
				if (A[i] == id) {
					index = i;
					break;
				}
			}
			if (index == -1) {
				printf ("NOT FOUND\n");
				continue;
			}
			size--;
			for (int i = index; i < size; i++) {
				C[A[i + 1]]++;
				A[index] = A[index + 1];
			}
			//for (int i = 0; i < index; i++) {
				//C[A[i]]++;
			//}
			printf ("%d\n", C[id]);
		}
	}
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
