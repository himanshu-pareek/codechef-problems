#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct SegmentTreeNode {
	ll prefixMaxSum, suffixMaxSum, maxSum, sum;
	
	void assignLeafValue (SegmentTreeNode node) {
		prefixMaxSum = suffixMaxSum = maxSum = sum = node.sum;
	}
	
	void merge (SegmentTreeNode & left, SegmentTreeNode & right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max (left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max (right.suffixMaxSum, left.suffixMaxSum + right.sum);
		maxSum = max ({prefixMaxSum, suffixMaxSum, left.maxSum, right.maxSum, left.suffixMaxSum + right.prefixMaxSum});
	}
	
	SegmentTreeNode getValue () {
		return *this;
	}
};

template < class T, class V >
class SegmentTree {
	vector < SegmentTreeNode > tree;
	int N;
	
	private:
	int getSegmentTreeSize (int n) {
		int sz = 1;
		for (;sz < N; sz <<= 1);
		return sz << 1;
	}
	
	void buildTree (vector < T > & arr, int low, int high, int pos) {
		if (low == high) {
			tree[pos].assignLeafValue (arr[low]);
			return;
		}
		int mid = low + (high - low) / 2;
		buildTree (arr, low, mid, 1 + (pos << 1));
		buildTree (arr, mid + 1, high, 2 + (pos << 1));
		tree[pos].merge (tree[1 + (pos << 1)], tree[2 + (pos << 1)]);
	}
	
	void update (int index, T value, int low, int high, int pos) {
		if (index < low || index > high) return;
		if (low == high) {
			tree[pos].assignLeafValue (value);
			return;
		}
		int mid = low + (high - low) / 2;
		update (index, value, low, mid, 1 + (pos << 1));
		update (index, value, mid + 1, high, 2 + (pos << 1));
		tree[pos].merge (tree[1 + (pos << 1)], tree[2 + (pos << 1)]);
	}
	
	SegmentTreeNode query (int left, int right, int low, int high, int pos) {
		if (left <= low && right >= high) {
			return tree[pos];
		}
		
		//if (left > right) {
			//return 
		
		int mid = (low + high) / 2;
		if (left > mid) {
			return query (left, right, mid + 1, high, 2 + (pos << 1));
		} else if (right <= mid) {
			return query (left, right, low, mid, 1 + (pos << 1));
		}
		
		SegmentTreeNode leftResult = query (left, right, low, mid, 1 + (pos << 1));
		SegmentTreeNode rightResult = query (left, right, mid + 1, high, 2 + (pos << 1));
		SegmentTreeNode result;
		result.merge (leftResult, rightResult);
		return result;
	}
	
	public:
	SegmentTree (vector < T > & arr) {
		N = arr.size();
		tree.resize (getSegmentTreeSize(N));
		buildTree (arr, 0, N - 1, 0);
	}
	
	~SegmentTree () {
		tree.resize (0);
	}
	
	V query (int left, int right) {
		SegmentTreeNode result = query (left, right, 0, N - 1, 0);
		return result.getValue();
	}
	
	void update (int index, T value) {
		update (index, value, 0, N - 1, 0);
	}
};

void solve() {
	int n, q;
	scanf ("%d %d", &n, &q);
	vector < ll > b (n);
	for (ll & x : b) scanf ("%lld", &x);
	vector < SegmentTreeNode > c (n);
	for (int i = 0; i < n; i++) {
		c[i] = (SegmentTreeNode) {b[i], b[i], b[i], b[i]};
	}
	SegmentTree < SegmentTreeNode, SegmentTreeNode > st (c);
	while (q--) {
		char type;
		scanf (" %c", &type);
		if (type == 'Q') {
			int x, y;
			scanf ("%d %d", &x, &y);
			x--, y--;
			ll one = 0, two = 0, three = 0;
			// get maxSuffix sum from 0 to x - 1
			if (x >= 0)
				one = st.query (0, x).suffixMaxSum;
			// get maxPrefix sum from y + 1 to n - 1
			if (x == y) { 
				y++;
				if (y < n)
					two = max (st.query (y, n - 1).prefixMaxSum, 0LL);
			} else {
				two = st.query (y, n - 1).prefixMaxSum;
			}
			// get sum from x to y
			if (x + 1 <= y - 1)
				three = st.query (x + 1, y - 1).sum;
			// add all three
			ll answer = one + two + three;
			printf ("%lld\n", answer);
		} else {
			int x; ll y;
			scanf ("%d %lld", &x, &y);
			x--;
			// Update => b[x] = y
			SegmentTreeNode node = (SegmentTreeNode) {y, y, y, y};
			st.update (x, node);
		}
	}
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
