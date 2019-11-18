#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;

int main() {
	int T, N, M, u, v;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector < int > degree (N, 0);
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			u--; v--;
			degree[u] = 1 - degree[u];
			degree[v] = 1 - degree[v];
		}
		if (M % 2 == 0) {
			cout << 1 << endl;
			for (int i = 0; i < N; i++) {
				cout << 1 << " ";
			}
			cout << endl;
		} else {
			int oddIndex = -1;
			for (int i = 0; i < N; i++) {
				if (degree[i]) {
					oddIndex = i;
					break;
				}
			}
			if (oddIndex != -1) {
				cout << 2 << endl;
				for (int i = 0; i < N; i++) {
					cout << (1 + (i == oddIndex)) << " ";
				}
				cout << endl;
			} else {
				cout << 3 << endl;
				for (int i = 0; i < N; i++) {
					if (i == u) {
						cout << 2 << " ";
					} else if (i == v) {
						cout << 3 << " ";
					} else {
						cout << 1 << " ";
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
