#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct element {
	int index;
	int value;
	int parent;
	
	bool operator < (const element & e) const {
		if (value == e.value) {
			return index < e.index;
		}
		return value < e.value;
	}
	
};

int main() {
	int n, k, p, A, B;
	scanf ("%d %d %d", &n, &k, &p);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", & x);
	vector < element > elements (n);
	for (int i = 0; i < n; i++) {
		elements[i] = {i, a[i], 0};
	}
	sort (elements.begin(), elements.end());
	int parent = 0;
	for (int i = 1; i < n; i++) {
		if (elements[i].value - elements[i - 1].value > k) {
			parent++;
		}
		elements[i].parent = parent;
	}
	for (int i = 0; i < n; i++) {
		a[elements[i].index] = elements[i].parent;
	}
	while (p--) {
		scanf ("%d %d", &A, &B);
		if (a[A-1] == a[B-1]) {
			printf ("Yes");
		} else {
			printf ("No");
		}
		printf ("\n");
	}
	return 0;
}
