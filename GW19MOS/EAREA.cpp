#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

struct Point {
	double x;
	double y;
};

Point middlePoint (Point p1, Point p2) {
	Point p3;
	p3.x = (p1.x + p2.x) / 2.0;
	p3.y = (p1.y + p2.y) / 2.0;
	return p3;
}

int main() {
	int n;
	scanf ("%d", &n);
	vector < Point > a (n);
	for (int i = 0; i < n; i++) {
		scanf ("%lf %lf", &a[i].x, &a[i].y);
	}
	vector < Point > b (n);
	for (int i = 0; i < n; i++) {
		int ip1 = i + 1;
		if (ip1 == n) ip1 = 0;
		b[i] = middlePoint (a[i], a[ip1]);
	}
	// Calculate area of polygon made by points in b
	double area = 0.0;
	for (int i = 0; i < n; i++) {
		int ip1 = i + 1;
		if (ip1 == n) ip1 = 0;
		area += (b[i].x * b[ip1].y) - (b[i].y * b[ip1].x);
	}
	area = area / 2.0;
	printf ("%.7lf\n", area);
}
	
