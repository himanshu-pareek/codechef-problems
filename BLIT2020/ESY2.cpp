#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, x;
		scanf ("%d", &N);
		vector < int > count (N + 1);
		for (int i = 0; i < N; i++) {
			scanf ("%d", &x);
			count[x]++;
		}
		printf ("0 ");
		for (int i = 1; i <= N; i++) {
			if (count[i] >= N / 2) printf ("%d\n", i);
		}
	}
	return 0;
}
