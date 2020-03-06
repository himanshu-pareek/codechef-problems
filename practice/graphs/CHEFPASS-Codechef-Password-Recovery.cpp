#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

vector < int > P, R;

void init (int i) {
	P[i] = i;
	R[i] = 1;
}

int find (int i) {
	if (i != P[i]) P[i] = find (P[i]);
	return P[i];
}

void merge (int i, int j) {
	int pu = find (i);
	int pv = find (j);
	if (pu == pv) return;
	if (R[pu] < R[pv]) {
		swap (pu, pv);
	}
	if (R[pu] == R[pv]) {
		R[pu]++;
	}
	P[pv] = pu;
}

int getIndex (char c) {
	if (c >= 'A' & c <= 'Z') return c - 'A';
	return 26 + (c - 'a');
}

int main() {
	ios_base::sync_with_stdio (false);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n;
		vector < string > a (n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> m;
		vector < string > b (m);
		for (int i = 0; i < m; i++) cin >> b[i];
		n = 52;
		vector < int > degree (n);
		for (string s : a) {
			degree[getIndex(s[0])]++;
			degree[getIndex(s[1])]++;
		}
		P.resize (n); R.resize (n);
		for (int i = 0; i < n; i++) init (i);
		for (string s : b) {
			merge (getIndex(s[0]), getIndex(s[1]));
		}
		vector < int > oddVertex (n);
		for (int i = 0; i < n; i++) {
			if (degree[i] & 1) {
				oddVertex[find (i)]++;
			}
		}
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (oddVertex[find(i)] & 1) {
				possible = false;
				break;
			}
		}
		if (possible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
		
