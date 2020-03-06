#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void printVector (vector < int > vec) {
    for (int x : vec) {
        cout << x << "\t";
    }
    cout << endl << "--------------------------" << endl;
}

struct SegmentTree {
	vector < int > tree;
	int n;
	
	int left (int x) { return 2 * x + 1; }
	
	int right (int x) { return 2 * x + 2; }
	
	int parent (int x) { return (x - 1) / 2; }
	
	SegmentTree (vector < int > & a) {
		n = (int) a.size();
		tree.resize (4 * n, 0);
		buildTree (a, 0, n - 1, 0);
	}
	
	void buildTree (vector < int > & a, int low, int high, int pos) {
		if (low == high) {
			tree[pos] = a[low];
			return;
		}
		int mid = low + (high - low) / 2;
		buildTree (a, low, mid, left (pos));
		buildTree (a, mid + 1, high, right (pos));
		tree[pos] = max (tree[left(pos)], tree[right(pos)]);
	}
	
	void updateUtil (int index, int val, int low, int high, int pos) {
		if (index < low || index > high) return;
		if (low == high) {
			tree[pos] = val;
			return;
		}
		int mid = low + (high - low) / 2;
		updateUtil (index, val, low, mid, left (pos));
		updateUtil (index, val, mid + 1, high, right (pos));
		tree[pos] = max (tree[left(pos)], tree[right(pos)]);
	}
	
	void update (int index, int val) {
		updateUtil (index, val, 0, n - 1, 0);
	}
	
	int queryUtil (int l, int r, int low, int high, int pos) {
		if (l > high || r < low) {
			return INT_MIN;
		}
		if (l <= low && r >= high) {
			return tree[pos];
		}
		int mid = low + (high - low) / 2;
		return max (queryUtil (l, r, low, mid, left (pos)),
					queryUtil (l, r, mid + 1, high, right (pos)));
	}
	
	int query (int l, int r) {
		return queryUtil (l, r, 0, n - 1, 0);
	}
	
};

int main () {
    int arr[] = {-1, 2, 4, 0};
    vector < int > a;
    for (int i = 0; i < 4; i++) {
        a.push_back (arr[i]);
    }
    printVector (a);
    SegmentTree st(a);
    // printVector (st.tree);
    while (true) {
        int mode, l, r, index, delta, startIndex, endIndex;
        cin >> mode;
        switch (mode) {
            case 0: cout << "Enter qlow and qhigh: ";
                    cin >> l >> r;
                    cout << st.query (l, r) << endl;
                    break;
            case 1: cout << "Enter index and delta: ";
                    cin >> index >> delta;
                    st.update (index, delta);
                    a[index] += delta;
                    printVector (a);
                    break;
            default: exit(0);
        }
    }
}
  
