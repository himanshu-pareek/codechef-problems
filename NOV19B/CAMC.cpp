#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>

#define pii pair < int, int >

using namespace std;

void solve () {
    int N, M;
    scanf ("%d %d", &N, &M);
    vector < int > A (N);
    for (int & x : A) scanf ("%d", & x);

    vector < vector < int > > vec (M);
    int ind = 0;
    for (int x : A) {
        vec[ind].push_back (x);
        ind = (ind + 1) % M;
    }
    vector < int > indexes (M, 0);
    // priority_queue < pii > maxpq;
    priority_queue < pii, vector < pii >, greater < pii > > minpq;
    set < pii > s;
    for (int i = 0; i < M; i++) {
        sort (vec[i].begin(), vec[i].end());
        minpq.push ({vec[i][0], i});
        s.insert ({vec[i][0], i});
    }
    int minDiff = INT_MAX;
    while (true) {
        pii p = minpq.top(); minpq.pop();
        pii q = *(s.rbegin());
        minDiff = min (minDiff, q.first - p.first);
        indexes[p.second]++;
        s.erase (p);
        if (indexes[p.second] == vec[p.second].size()) {
            break;
        }
        minpq.push ({vec[p.second][indexes[p.second]], p.second});
        s.insert ({vec[p.second][indexes[p.second]], p.second});
    }

        // vector < int > A1, A2;
        // bool flag = true;
        // for (int x : A) {
        //     if (flag) A1.push_back (x);
        //     else A2.push_back (x);
        //     flag = !flag;
        // }
        // sort (A1.begin(), A1.end());
        // sort (A2.begin(), A2.end());
        // int minDiff = INT_MAX;
        // int i = 0, j = 0;
        // while (i < A1.size() && j < A2.size()) {
        //     minDiff = min (minDiff, abs (A1[i] - A2[j]));
        //     if (A1[i] < A2[j]) {
        //         i++;
        //     } else {
        //         j++;
        //     }
        // }
    printf ("%d\n", minDiff);
    // return;
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}