#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct triple {
	int x, y, z;
};

int main() {
	int T, N, K, M;
	cin >> T;
	while (T--) {
		cin >> N >> K >> M;
		// cout << N << K << M;
		vector < triple > vec (M);
		for (int i = 0; i < M; i++) {
			cin >> vec[i].x >> vec[i].y >> vec[i].z;
		}
		sort (vec.begin(), vec.end(), [&] (const triple & t1, const triple & t2) {
			return t1.z < t2.z;
		});
		vector < int > A (N + 1, -1);
		vector < int > count (K + 1, 0);
		vector < int > last (K + 1, 1);
		int start = 1;
		bool possible = true;
		for (triple tri : vec) {
			int x = tri.x, y = tri.y, z = tri.z;
			if (A[z] != -1) {
				possible = false;
				break;
			}
			A[z] = x;
			if (count[x] >= y) {
				possible = false;
				break;
			}
			int rem = y - count[x] - 1;
			start = last[x];
			while (rem > 0) {
				if (start >= z) {
					possible = false;
					break;
				}
				if (A[start] == -1) {
					A[start] = x;
					rem--;
				}
				start++;
			}
			if (!possible) break;
			count[x] = y;
			last[x] = z;
		}
		while (start <= N && A[start] != -1) {
			start++;
		}
		for (int i = start; i <= vec.back().z; i++) {
			if (A[i] != -1) {
				count[A[i]] = -1;
			}
		}
		int value = -1;
		for (int i = 1; i <= K; i++) {
			if (count[i] != -1) {
				value = i; break;
			}
		}
		if (value == -1) possible = false;
		for (int i = start; i <= N; i++) {
			if (A[i] == -1) A[i] = value;
		}
		for (int i = 1; i <= N; i++){
			if (A[i] == -1) {
				possible = false;
				break;
			}
		}
		if (!possible) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (int i = 1; i <= N; i++) {
				cout << A[i] << " ";
			}
			cout << endl;
		}
	}
}
