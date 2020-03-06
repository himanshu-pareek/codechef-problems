#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mx = 2e6 + 5;
const int ALPHA = 28;
const ll mod = 1e9 + 7;

struct state {
	int len;
	int link;
	int next[ALPHA];
	int mn, mx, count;
	state() {
		len = link = count = 0;
		mn = (1 << 30);
		mx = -1;
		memset (next, -1, sizeof (next));
	}
};

class SuffixAutomata {
	public:
		state st[2 * mx];
		int sz;
		int last;
		int totalLength;
		void init() {
			for (int i = 1; i < 2 * mx; i++) st[i] = state();
			st[0].len = 0;
			st[0].link = -1;
			sz = 1;
			last = 0;
			totalLength = 0;
		}
		
		void extend (char cc, int which) {
			//cout << cc << " " << which << endl;
			int c = cc - 'a';
			int curr = sz++;
			st[curr].len = st[last].len + 1;
			int p = last;
			while (p != -1 && st[p].next[c] == -1) {
				st[p].next[c] = curr;
				p = st[p].link;
			}
			if (p == -1) {
				st[curr].link = 0;
			} else {
				int q = st[p].next[c];
				if (st[q].len == st[p].len + 1) {
					st[curr].link = q;
				} else {
					int clone = sz++;
					st[clone].len = st[p].len + 1;
					st[clone].link = st[q].link;
					for (int i = 0; i < ALPHA; i++) st[clone].next[i] = st[q].next[i];
					while (p != -1 && st[p].next[c] == q) {
						st[p].next[c] = clone;
						p = st[p].link;
					}
					st[q].link = st[curr].link = clone;
				}
			}
			st[curr].mn = st[curr].mx = which;
			st[curr].count = 1;
			totalLength++;
			last = curr;
		}
		
		vector < int > v[2 * mx], dfsorder;
		
		ll process() {
			ll ret = 0;
			for (int i = 0; i < sz; i++) {
				if (st[i].link != -1) {
					v[st[i].link].push_back (i);
				}
			}
			
			dfs (0);
			
			for (int x : dfsorder) {
				int p = st[x].link;
				if (p == -1) continue;
				st[p].count += st[x].count;
				st[p].mn = min (st[p].mn, st[x].mn);
				st[p].mx = max (st[p].mx, st[x].mx);
				
				if (st[x].count < 2) continue;
				int take = min (st[x].len, st[x].mx - st[x].mn);
				ret = max (ret, max (1ll * take * (totalLength - st[x].mn), 1LL * take * (st[x].mx - take)));
			}
			
			return ret;
		}
		
		void dfs (int x) {
			for (int n : v[x]) {
				dfs (n);
			}
			dfsorder.push_back (x);
		}
} SA;

int main() {
	int n;
	scanf ("%d", &n);
	string s;
	cin >> s;
	SA.init();
	
	for (int i = 0; i < n; i++) {
		SA.extend (s[i], i + 1);
	}
	printf ("%lld\n", SA.process());
	return 0; 
}
					
	
