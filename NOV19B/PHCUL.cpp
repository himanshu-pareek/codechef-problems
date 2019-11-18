#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;
typedef long long ll;

struct point {
    int x, y;
};

inline double calculateDistance (point p1, point p2) {
    return sqrt ((ll)(p1.x - p2.x) * (ll)(p1.x - p2.x) + (ll)(p1.y - p2.y) * (ll)(p1.y - p2.y));
}

void solve () {
    int N, M, K, x, y;
    scanf ("%d %d", &x, &y);
    point P = {x, y};
    scanf ("%d %d %d", &N, &M, &K);
    vector < point > a (N), b (M), c (K);
    for (point & p : a) scanf ("%d %d", &(p.x), &(p.y));
    for (point & p : b) scanf ("%d %d", &(p.x), &(p.y));
    for (point & p : c) scanf ("%d %d", &(p.x), &(p.y));

    vector < double > ac (N), bc (M);
    for (int i = 0; i < N; i++) {
        double minDist = calculateDistance (a[i], c[0]);
        for (point p : c) {
            minDist = min (minDist, calculateDistance (a[i], p));
        }
        ac[i] = minDist;
    }
    for (int i = 0; i < M; i++) {
        double minDist = calculateDistance (b[i], c[0]);
        for (point p : c) {
            minDist = min (minDist, calculateDistance (b[i], p));
        }
        bc[i] = minDist;
    }

    double minDist = numeric_limits<double>::max();
    for (int i = 0; i < N; i++) {
        double dist1 = calculateDistance (P, a[i]);
        for (int j = 0; j < M; j++) {
            double dist2 = calculateDistance (a[i], b[j]);
            double dist3 = calculateDistance (P, b[j]);
            minDist = min (minDist, dist2 + min (dist1 + bc[j], dist3 + ac[i]));
        }
        
    }

    printf ("%.10f\n", minDist);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
