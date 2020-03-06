#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

template < typename T >
void printVector (const vector < T > & vec) {
	for (const T t : vec) {
		cout << t << " ";
	}
	cout << endl << "--------------------------" << endl;
}

void solve () {
	int n, k, q, l, r;
	scanf ("%d %d %d", &n, &k, &q);
	string s;
	cin >> s;
	vector < int > count0 (n, 0), count1 (n, 0);
	count0[0] = s[0] == '0';
	count1[0] = s[0] == '1';
	for (int i = 1; i < n; i++) {
		count0[i] = count0[i - 1] + (s[i] == '0');
		count1[i] = count1[i - 1] + (s[i] == '1');
	}
	vector < int > lastIndex (n);
	for (int i = 0; i < n; i++) {
		int left = i, right = n - 1;
		int ans = i - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int c0 = count0[mid] - count0[i] + (s[i] == '0');
			int c1 = count1[mid] - count1[i] + (s[i] == '1');
			
			if (c0 <= k && c1 <= k) {
				// go to right
				ans = mid;
				left = mid + 1;
			} else {
				// go to left
				right = mid - 1;
			}
		}
		lastIndex[i] = ans;
	}
	vector < long > total (n + 1, 0L);
	for (int i = 1; i <= n; i++) {
		total[i] = total[i - 1] + (long) (lastIndex[i - 1] - i + 2);
	}
	printVector (lastIndex);
	printVector (total);
	while (q--) {
		scanf ("%d %d", &l, &r);
		long answer = total[r] - total[l - 1];
		printf ("%ld\n", answer);
	}
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
	
