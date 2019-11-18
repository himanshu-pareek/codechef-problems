#include <stdio.h>
#define MOD 987654319
typedef long long ll;

int main() {
	int N;
	scanf ("%d", &N);
	int A[N];
	for (int i = 0; i < N; i++) {
		scanf ("%d", A + i);
	}
	ll dp[N][7];
	for (int i = 0; i < N; i++) {
		dp[i][6] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i] > A[j]) {

			}
		}
	}
}
