#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 1e3 + 10;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int N, Q, y;
		scanf ("%d", &N);
		vector < int > A (N);
		for (int & x : A) scanf ("%d", &x);
		vector < int > count (mx);
		int cnt = 0;
		int sum = 0;
		for (int x : A) {
			if (count[x] == 0) cnt++;
			count[x]++;
			sum += x;
		}
		while (cnt > 1) {
			A.push_back (sum / N);
			count[A[A.size() - (N + 1)]]--;
			if (count[A[A.size() - (N + 1)]] == 0) cnt--;
			if (count[A.back()] == 0) cnt++;
			count[A.back()]++;
			sum -= A[A.size() - (N + 1)];
			sum += A.back();
		}
		scanf ("%d", &Q);
		while (Q--) {
			scanf ("%d", &y);
			y--;
			if (y < A.size()) cout << A[y] << endl;
			else cout << A.back() << endl;
		}
	}
	return 0;
}
