#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 5;
const int inf = 1e8 + 5;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, M, x;
		scanf ("%d %d", &N, &M);
		vector < int > A (N);
		for (int & x : A) scanf ("%d", &x);
		vector < int > V (M);
		for (int & x : V) scanf ("%d", &x);
		int S = 0;
		for (int x : A) {
			S = max (S, x);
		}
		vector < int > dp (S + 1, inf);
		dp[0] = 0;
		for (int x : V) {
			for (int s = x; s <= S; s++) {
				if (dp[s - x] != inf)
					dp[s] = min (dp[s], 1 + dp[s - x]);
			}
		}
		//for (int i = 0; i <= S; i++) cout << dp[i] << " ";
		//cout << endl;
		int sum = 0;
		for (int x : A) {
			sum += dp[x];
		}
		printf ("%d\n", sum);
	}
	return 0;
}
