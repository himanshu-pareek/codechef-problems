#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main() {
	int T; ll L, R, ans;
	cin >> T;
	while (T--) {
		cin >> L >> R;
		ans = 0;
		int i;
		for (i = 63; i >= 0; i--) {
			int bit_L = (L >> i) & 1;
			int bit_R = (R >> i) & 1;
			if (bit_L == bit_R) {
				ans |= (((ll) bit_L) << i);
			} else {
				ans |= (1LL << i);
				break;
			}
		}
		for ( ; i >= 0; i--) {
			ans |= (1LL << i);
		}
		cout << ans << endl;
	}
}
