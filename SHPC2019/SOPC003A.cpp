#include <bits/stdc++.h>
using namespace std;


int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		vector < int > A (n);
		for (int & x : A) scanf ("%d", &x);
		sort (A.begin(), A.end());
		auto search = [&] (int x) {
			// count the numbers of element
			// which are <= x
			int low = 0, high = n - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (A[mid] <= x) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			return low;
		};
		long pairs = 0L;
		for (int x : A) {
			pairs += (search (2 * x) - search ((x + 1) / 2 - 1) - 1);
		}
		printf ("%ld\n", pairs / 2);
	}
	return 0;
}
