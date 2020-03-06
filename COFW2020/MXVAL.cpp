#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int getInteger (int a, int b) {
	return a + rand() % (b - a + 1);
}

void printArray (vector < int > & a) {
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int n;
	scanf ("%d", &n);
	//n = getInteger (5, 10);
	vector < int > A (n);
	for (int & x : A) {
		scanf ("%d", &x);
		//x = getInteger (-100, 100);
	}
	
	priority_queue < ll > pq;
	for (int x : A) {
		pq.push ((ll) x);
	}
	ll ans = 0LL;
	while (pq.size() >= 2) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		ans += x + y;
		pq.push (x + y);
	}
	printf ("%lld\n", ans);
	return 0;
}
