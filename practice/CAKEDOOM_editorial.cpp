/**
 * June 2012 Codechef Long Contest
 *
 * Problem:     CAKEDOOM
 * Author:      Anton Lunyov (Tester)
 * Complexity:  O(T * N * K * K)
 * Timing:      0.09 out of 2
 *
 * Inspired by solution of Gennady Korotkevich.
 * Very neat solution in which we did not consider any cases at all!
 *
 * The worst test case for this solution is 1000 copies of the following test
 * 10
 * ?989898989...98988 (length 100)
 * But we have no such test because we had no idea about such solution :)
 * For this test timing of this solution can be much higher.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int k;
		string s;
		cin >> k >> s;
		int n = s.length();

		string ans = "NO";
		for (char c = '0'; c < '0' + k; ++c) {
			string w = s;
			if (w[0] != '?' && w[0] != c) {
				continue;
			}

			bool good = true;
			w[0] = c;
			for (int i = 1; i < n; ++i) {
				bool ok = false;
				for (char d = '0'; d < '0' + k; ++ d) {
					if (w[i] != '?' && w[i] != d) {
						continue;
					}
					if (d != w[i - 1] && d != w[(i + 1) % n]) {
						w[i] = d;
						ok = true;
						break;
					}
				}
				if (!ok) {
					good = false;
					break;
				}
			}
			if (good) {
				ans = w;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
