#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct node {
    ll num_subarray;
    int len, left, right;

    node (int value = 0) {
        assert (value == 0 || value == 1);
        len = 1;
        num_subarray = left = right = value;
    }

    void print() {
        cout << "{" << num_subarray << ", " << len << ", " << left << ", " << right << "}";
        cout << endl;
    }
};

void printVector (vector < node > &vec) {
    for (node n : vec) {
        n.print();
    }
    cout << "-----------------" << endl;
}

struct SegmentTree {

    vector < node > tree;
    int n;
    int x;

    inline int getValue (int value) {
        return (value < x);
    }

    node merge (node a, node b) {
        node u;
        u.len = a.len + b.len;
        u.num_subarray = (ll)a.num_subarray + (ll)b.num_subarray + (1ll * a.right * b.left);
        u.left = a.left;
        if (a.left == a.len) {
            u.left += b.left;
        }
        u.right = b.right;
        if (b.right == b.len) {
            u.right += a.right;
        }
        return u;
    }

    void buildUtil (int low, int high, int pos, int value) {
        if (low > high)
            return;
        if (low == high) {
            tree[pos] = node(value);
            return;
        }
        int mid = low + (high - low) / 2;
        buildUtil (low, mid, 2 * pos + 1, value);
        buildUtil (mid + 1, high, 2 * pos + 2, value);
        tree[pos] = merge (tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    SegmentTree (int n, int x) {
        this -> n = n;
        this -> x = x;
        int h = ceil (log2 (n));
        tree.resize ((1 << ((ll)h + 1)) - 1);
        buildUtil (0, n - 1, 0, getValue (0));
        // printVector (tree);
        // tree.resize ((1 << ((ll)h + 1)) - 1, node());
        // for (int i = 0; i < n; i++) {
        //     update (i, 0);
        // }
        // printVector (tree);
        // update (0, n - 1, 0);
    }

    void updateUtil (int index, int value, int low, int high, int pos) {
        if (index < low || index > high) {
            return;
        }
        if (low == high) {
            tree[pos] = node (value);
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid)
            updateUtil (index, value, low, mid, 2 * pos + 1);
        else 
            updateUtil (index, value, mid + 1, high, 2 * pos + 2);

        tree[pos] = merge (tree[2 * pos + 1], tree[2 * pos + 2]);
    }

    void update (int index, int value) {
        value = getValue (value);
        updateUtil (index, value, 0, n - 1, 0);
    }

    node queryUtil (int l, int r, int low, int high, int pos) {
        if (r < low || l > high) {
            return node(0);
        }
        if (l <= low && r >= high) {
            return tree[pos];
        }
        int mid = low + (high - low) / 2;
        node a = queryUtil (l, r, low, mid, 2 * pos + 1);
        node b = queryUtil (l, r, mid + 1, high, 2 * pos + 2);
        return merge (a, b);
    }

    ll query (int l, int r) {
        node u = queryUtil (l, r, 0, n - 1, 0);
        return u.num_subarray;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q, L, R;
    cin >> N >> Q >> L >> R;
    SegmentTree st1 (N, L);
    SegmentTree st2 (N, R + 1);
    int x, l, r;
    while (Q--) {
        cin >> x >> l >> r;
        if (x == 1) {
            l--;
            st1.update (l, r);
            st2.update (l, r);
        } else {
            l--, r--;
            ll ansl = st1.query (l, r);
            ll ansr = st2.query (l, r);
            cout << (ansr - ansl) << endl;
        }
    }
    return 0;
}