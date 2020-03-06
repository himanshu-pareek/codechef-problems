#include <bits/stdc++.h>
using namespace std;

void solve () {
	int N;
	scanf ("%d", &N);
	vector < int > A (N);
	for (int & x : A) scanf ("%d", &x);
	int index = -1;
	for (int i = 0; i < N - 1; i++) {
		if (A[i] >= A[i + 1]) {
			index = i;
			break;
		}
	}
	bool possible = true;
	for (int ind : {index, index + 1}) {
		vector < int > indices;
		for (int i = 0; i < N; i++) {
			if (i != ind) {
				indices.push_back (i);
			}
		}
		possible = true;
		for (int i = 0; i < N - 2; i++) {
			if (A[indices[i]] >= A[indices[i + 1]]) {
				possible = false;
				break;
			}
		}
		if (possible) {
			break;
		}
	}
	if (!possible) {
		printf ("FALSE\n");
	} else {
		printf ("TRUE\n");
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
