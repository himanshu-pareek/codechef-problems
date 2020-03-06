#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int > ;

const int mx = 1e4;

int main() {
	int n;
	scanf ("%d", &n);
	vector < int > W (n), P (n);
	int sumW = 0, sumP = 0;
	int profit;
	for (int i = 0; i < n; i++) {
		int low = sumW + 1, high = mx;
		printf ("1 %d %d\n", i + 1, high);
		fflush (stdout);
		int pro;
		scanf ("%d", &pro);
		while (low <= high) {
			int mid = low + (high - low) / 2;
			printf ("1 %d %d\n", i + 1, mid);
			fflush (stdout);
			scanf ("%d", &profit);
			if (profit >= pro) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		W[i] = low - sumW;
		P[i] = pro - sumP;
		sumW = low;
		sumP = pro;
	}
	printf ("2\n");
	for (int i = 0; i < n; i++) {
		printf ("%d ", W[i]);
	}
	printf ("\n");
	for (int i = 0; i < n; i++) {
		printf ("%d ", P[i]);
	}
	printf ("\n");
	return 0;
}
