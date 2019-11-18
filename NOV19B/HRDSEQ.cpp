#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void solve () {
    int N;
    scanf ("%d", &N);
    if (N <= 2) {
        printf ("%d\n", N);
        return;
    }
    vector < int > seq, last_occu (150, -1);
    seq.push_back (0);
    for (int curr = 1; curr < N; curr++) {
        int x = seq[curr - 1];
        if (last_occu[x] == -1) {
            seq.push_back (0);
        } else {
            seq.push_back (curr - 1 - last_occu[x]);
        }
        last_occu[x] = curr - 1;
    }
    int element = seq.back();
    int count = 0;
    for (int x : seq) {
        if (x == element) {
            count++;
        }
    }
    printf ("%d\n", count);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}

