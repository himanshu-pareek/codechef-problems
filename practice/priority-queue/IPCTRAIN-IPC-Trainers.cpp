#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const int mx = 1e5 + 5;

struct Trainer {
	ll d, t, s;
};

struct CompareTrainer {
	bool operator() (Trainer const& t1, Trainer const & t2) {
		return t1.s < t2.s;
	}
};

void solve() {
	ll N, D;
	scanf ("%lld %lld", &N, &D);
	vector < Trainer > trainers (N);
	for (Trainer & t : trainers) {
		scanf ("%lld %lld %lld", &(t.d), &(t.t), &(t.s));
	}
	vector < Trainer > days[mx];
	for (Trainer t : trainers) {
		days[t.d].push_back (t);
	}
	priority_queue < Trainer, vector < Trainer >, CompareTrainer > pq;
	for (int day = 1; day <= D; day++) {
		for (Trainer t : days[day]) {
			pq.push (t);
		}
		if (!pq.empty()) {
			Trainer t = pq.top(); pq.pop();
			if (t.t > 1) {
				pq.push ({t.d, t.t - 1, t.s});
			}
		}
	}
	ll answer = 0;
	while (!pq.empty()) {
		Trainer t = pq.top(); pq.pop();
		answer += (t.t * t.s);
	}
	printf ("%lld\n", answer);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
