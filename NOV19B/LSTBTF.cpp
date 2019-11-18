#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 29;

bool dp[11][mx][81 * mx];
vector < int > squares;

bool valid (ll n) {
    ll sum = 0;
    while (n) {
        int digit = n % 10;
        if (digit == 0) return false;
        sum += (digit * digit);
        n /= 10;
    }
    ll x = sqrt (sum);
    return (x * x == sum);
}

void solve () {
    int N;
    scanf ("%d", &N);
    int remaining_digits = N;
    int currentSum = 0;
    for (int i = 1; remaining_digits && i <= 9; i++) {
		// while there are digits remaining
		// iterate for i from 1 (least digit) to 9 (maximum digit)
		int cnt = remaining_digits;
		while (true) {
			// total remaining digits = remaining_digits [to be contributed by i, i + 1, ... , 9]
			// sum should be square of some number
			// sum = (contribution of digits 1, 2, ..., i - 1) + (contribution of i) + (contribution of digits i + 1, ... , 9)
			// contribution of digits < i = currentSum
			// contribution of digit i = cnt * i * i
			// => (contribution of digits > i) = sum - (currentSum + cnt * i * i)
			// Since, sum should be perfect square
			// So, we will iterate for sum in squares array
			// for digits > i : number of digits = remaining_digits - cnt
			bool possible = false;
			for (int sum : squares) {
				int rest = sum - (currentSum + cnt * i * i);
				if (rest >= 0 && rest < 81 * mx) {
					if (dp[i + 1][remaining_digits - cnt][rest]) {
						possible = true;
						break;
					}
				}
			}
			if (possible) break;
			cnt--;
		}
		remaining_digits -= cnt;
		currentSum += cnt * i * i;
		while (cnt--) {
			printf ("%d", i);
		}
	}
	printf ("\n");
}


int main() {
	ios::sync_with_stdio (false); cin.tie (0);
	for (int i = 0; i * i <= (int)1e8; i++) {
		squares.push_back (i * i);
	}
	dp[10][0][0] = true;
	for (int firstDigit = 9; firstDigit > 0; firstDigit--) {
		for (int cntDigit = 0; cntDigit < mx; cntDigit++) {
			for (int sum = 0; sum < 81 * mx; sum++) {
				if (cntDigit == 0) {
					// sum should also be 0
					dp[firstDigit][cntDigit][sum] = (sum == 0);
				} else {
					dp[firstDigit][cntDigit][sum] |= dp[firstDigit + 1][cntDigit][sum];
					for (int cnt = 1; cnt <= cntDigit && cnt * firstDigit * firstDigit <= sum; cnt++) {
						dp[firstDigit][cntDigit][sum] |= dp[firstDigit + 1][cntDigit - cnt][sum - cnt * firstDigit * firstDigit];
					}
				}
			}
		}
	}
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
