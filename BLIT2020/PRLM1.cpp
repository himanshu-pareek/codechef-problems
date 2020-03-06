#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 5;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, M, x;
		scanf ("%d %d", &N, &M);
		vector < int > A (N);
		for (int & x : A) scanf ("%d", &x);
		vector < bool > V (mx);
		for (int i = 0; i < M; i++) {
			scanf ("%d", &x);
			V[x] = true;
		}
		auto largestDividor = [&] (int m) {
			int div = 1;
			for (int i = 1; i * i <= m; i++) {
				if (m % i == 0) {
					for (int j : {i, m / i}) {
						if (j > div && V[j]) div = j;
					}
				}
			}
			return div;
		};
		int sum = 0;
		for (int a : A) {
			int b = largestDividor (a);
			sum += a / b;
		}
		printf ("%d\n", sum);
	}
	return 0;
}
