#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int N;
	scanf ("%d", &N);
	string s;
	cin >> s;
	assert (s.size() == 2 * N);
	vector < int > score (2);
	vector < int > remaining (2, N);
	for (int i = 0; i < 2 * N; i++) {
		score[1 & i] += (s[i] == '1');
		remaining[1 & i]--;
		for (int a : {0, 1}) {
			int b = 1 - a;
			if (score[a] > score[b] + remaining[b]) {
				cout << (i + 1) << endl; return;
			}
		}
	}
	cout << 2 * N << endl;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
