#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector < int > tree;
    int n;

    // void buildSegmentTree (vector < int > tree, )

    SegmentTree (int a) {
        n = a;
        int h = ceil (log2 (n));
        int m = 1 << h;
        tree.resize ((m << 1) - 1, 0);
    }

    void updateUtil (int startIndex, int endIndex, int low, int high, int pos) {
        if (low > high || startIndex > high || endIndex < low) {
            return;
        }
        if (low == high) {
            tree[pos] = 1 - tree[pos];
            return;
        }
        int mid = low + (high - low) / 2;
        updateUtil (startIndex, endIndex, low, mid, (pos << 1) + 1);
        updateUtil (startIndex, endIndex, mid + 1, high, (pos << 1) + 2);
        tree[pos] = tree[(pos << 1) + 1] + tree[(pos << 1) + 2];
    }

    void update (int startIndex, int endIndex) {
        updateUtil (startIndex, endIndex, 0, n - 1, 0);
    }

    int queryUtil (int l, int r, int low, int high, int pos) {
        if (l <= low && r >= high) {
            return tree[pos];
        }
        if (l > high || r < low) {
            return 0;
        }
        int mid = low + (high - low) / 2;
        return queryUtil (l, r, low, mid, (pos << 1) + 1) +
                queryUtil (l, r, mid + 1, high, (pos << 1) + 1);
    }

    int query (int l, int r) {
        return queryUtil (l, r, 0, n - 1, 0);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree st (n);
    int op, a, b;
    while (q--) {
        cin >> op >> a >> b;
        if (op) {
            cout << st.query (a, b) << endl;
        } else {
            st.update (a, b);
        }
    }
    return 0;
}