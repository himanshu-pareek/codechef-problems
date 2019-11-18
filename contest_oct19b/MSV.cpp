#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int getRandomInt (int a, int b) {
    return a + (rand() % (b - a + 1));
}

void printVector (const vector < int > &vec) {
    for (const int x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

void calculateFactors (vector < int > &vec, int num) {
	for (int i = 1; i <= sqrt (num); i++) {
		if (num % i == 0) {
			vec.push_back (i);
			vec.push_back (num / i);
		}
	}
	if (vec[vec.size() - 1] == vec[vec.size() - 2]) {
		vec.pop_back ();
	}
}

int main() {
	int T, N, X;
	cin >> T;
	vector < vector < int > > factors (1000005);
	while (T--) {
		cin >> N;
		// N = getRandomInt (1, 100000);
		vector < int > count (1000005, 0);
		int ans = 0;
		
		// toremove
		// vector < int > A (N);
		
		for (int i = 0; i < N; i++) {
			cin >> X;
			// X = getRandomInt (1, 1000000);
			
			// toremove
			// A[i] = X;
			
			ans = max (ans, count[X]);
			if (factors[X].empty()) {
				calculateFactors (factors[X], X);
			}
			for (int factor : factors[X]) {
				count[factor]++;
			}
		}
		
		cout << ans << endl;
		
		/*
		//toremove
		int ans2 = 0;
		for (int i = 1; i < N; i++) {
			int temp = 0;
			for (int j = 0; j < i; j++) {
				if (A[j] % A[i] == 0) {
					temp++;
				}
			}
			ans2 = max (ans2, temp);
		}
		cout << ans2 << endl;
		
		if (ans != ans2) {
			cout << "ERROR for N = " << N << endl;
			printVector (A);
		} else {
			cout << "SUCCESS for N = " << N << endl;
		}
		//
		
		// cout << ans << endl; */
	}
	return 0;
}

