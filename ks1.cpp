#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool areEqual (vector < ll > &a, vector < ll > &b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void printVector (vector < int > &vec) {
    cout << endl;
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl << "--------------------" << endl;
}

ll countTriplets1 (vector < int > &a, int n) {
    unordered_map < int, vector < int > > m;
    m[0].push_back (-1);
    int x = 0;
    ll count = 0;
    for (int k = 0; k < n; k++) {
        x = x ^ a[k];
        // cout << "k = " << k << ", x = "  << x << endl;
        auto it = m.find(x);
        if (it != m.end()) {
            vector < int > vec = it -> second;
            for (int x : vec) {
                count += (ll)(max (0, k - x - 1));
            }
        }
        m[x].push_back (k);
    }
    return count;
}

ll countTriplets2 (vector < int > &a, int n) {
	ll count = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			
			for (int j = i + 1; j <= k; j++) {
				int xor1 = 0, xor2 = 0;	
				for (int l = i; l < j; l++) {
					xor1 = xor1 ^ a[l];
				}
				for (int l = j; l <= k; l++) {
					xor2 = xor2 ^ a[l];
				}
				if (xor1 == xor2) {
					count = count + (ll)1;
				}
			}
		}
	}
	return count;
}

vector < int > generateRandomVector () {
	// return {9, 2, 2};
	vector < int > ans;
	int size = rand() % 100 + 1;
	// int size = 3;
	while (size--) {
		int x = rand() % 10;
		ans.push_back (x);
	}
	return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        // cin >> n;
        /* vector < int > a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } */
        vector < int > a = generateRandomVector();
        ll count1 = countTriplets1 (a, a.size());
        ll count2 = countTriplets2 (a, a.size());
        cout << "Size: " << a.size() << endl;
        printVector (a);
        cout << ", Count1 = " << count1 << ", Count2 = " << count2;
        if (count1 == count2) {
        	cout << " Passed" << endl;
        } else {
        	cout << " Failed" << endl;
        	return 0;
        }
        // cout << count << endl;
    }
	return 0;
}

