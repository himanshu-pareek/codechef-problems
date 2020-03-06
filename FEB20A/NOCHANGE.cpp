#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n, P;
		scanf ("%d %d", &n, &P);
		vector < int > D (n);
		for (int & x : D) scanf ("%d", &x);
        bool done = false;
        // First check for a single element
        // such that element does not divide P
        for (int x : D) {
            if (P % x) {
                // x does not divide P
                int num = 1 + (P / x);
                printf ("YES");
                int i;
                for (i = 0; i < n && D[i] != x; i++) {
                    printf (" 0");
                }
                printf (" %d", num);
                i++;
                for (; i < n; i++) {
                    printf (" 0");
                }
                printf ("\n");
                done = true;
                break;
            }
        }
        if (done) continue;
        // Now, all elements divide P
        // iterate over two elements at a time
        // if, one does not divide another
        // we find our solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = D[i], b = D[j];
                if (a > b) continue;
                if (b % a) {
                    // a does not divide b
                    // take lots of a and single b with you
                    int num_a = ceil ((double)(P -b) / (double) a); 
                    int num_b = 1;
                    printf ("YES");
                    for (int k = 0; k < n; k++) {
                        if (k == i) {
                            printf (" %d", num_a);
                        } else if (k == j) {
                            printf (" %d", num_b);
                        } else {
                            printf (" 0");
                        }
                    }
                    printf ("\n");
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        if (done) continue;
        printf ("NO\n");
	}
	return 0;
}

