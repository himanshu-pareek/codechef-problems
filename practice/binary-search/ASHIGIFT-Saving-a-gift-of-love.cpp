#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int maxB = 10005;
const int maxC = 10005;
const ll mx = 1e18 + 5;

struct dish {
	int x;
	ll y;
};

struct clan {
	int p;
	ll q;
	ll r;
};

dish dishes[maxB];
clan clans[maxC];

int X, B, C;

bool isValid (ll group) {
	int i = 0, j = 0;
	while (i < B && j < C) {
		if (dishes[i].x < clans[j].p) {
			if (dishes[i].y > group) {
				return false;
			}
			group -= dishes[i].y;
			i++;
		} else {
			if (clans[j].q <= group) {
				group += clans[j].r;
			}
			j++;
		}
	}
	
	while (i < B) {
		if (dishes[i].y > group) {
			return false;
		}
		group -= dishes[i].y;
		i++;
	}
	
	return group > 0;
}

void solve () {
	scanf ("%d", &X);
	scanf ("%d", &B);
	for (int i = 0; i < B; i++) {
		scanf ("%d %lld", &dishes[i].x, &dishes[i].y);
	}
	scanf ("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf ("%d %lld %lld", &clans[i].p, &clans[i].q, &clans[i].r);
	}
	
	ll left = 1, right = mx;
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		if (isValid (mid)) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	
	printf ("%lld\n", left);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}

