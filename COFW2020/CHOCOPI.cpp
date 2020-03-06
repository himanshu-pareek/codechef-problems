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
	srand (time(0));
	int Q, x;
	scanf ("%d", &Q);
	priority_queue < int > left;
	priority_queue < int, vector < int >, greater < int > > right;
	ll p1 = 0, p2 = 0;
	vector < int > a;
	while (Q--) {
		scanf ("%d", &x);
		//x = getInteger (-100000000, 100000000);
		//a.push_back (x);
		//sort (a.begin(), a.end());
		//ll z = a[a.size()/2];
		//ll ans = 0;
		//for (int y : a) {
			//ans += abs (z - y);
		//}
		//ans = 2LL * ans;
		if (left.size() == right.size()) {
			if (left.empty() || left.top() >= x) {
				left.push (x);
				p1 += 1LL * left.top() - x;
			} else if (right.empty() || right.top() >= x) {
				p1 += 1LL * left.size() * (x - left.top());
				p2 -= 1LL * right.size() * (x - left.top());
				left.push (x);
			} else {
				p1 += 1LL * left.size() * (right.top() - left.top());
				p2 -= 1LL * right.size() * (right.top() - left.top());
				p2 += 1LL * x - right.top();
				left.push (right.top()); right.pop();
				right.push (x);
			}
		} else {
			// left.size = right.size + 1
			if (x >= left.top()) {
				p2 += 1LL * x - left.top();
				right.push (x);
			} else {
				int med = left.top();
				left.pop();
				left.push (x);
				p1 -= 1LL * ((int) left.size() - 1) * (med - left.top());
				p1 += left.top() - x;
				p2 += 1LL * right.size() * (med - left.top());
				right.push (med);
				p2 += 1LL * med - left.top();
			}
		}
		ll dist = 2LL * (p1 + p2);
		
		//if (dist == ans) {
			////cout << "passed" << endl;
		//} else {
			//cout << dist << " " << ans << endl;
			//printArray (a);
			//return 0;
		//}
		printf ("%lld\n", dist);
	}
	return 0;
}
