#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >; 

void solve() {
	int h, node;
	scanf ("%d", &h);
	int numQ = 0;
	if (h == 0) {
		printf ("3 1\n");
		flush (cout);
		scanf ("%d", &node);
		if (node == -1) {
			exit(0);
		}
		return;
	}
	bool foundLeaf = false;
	int currentNode = 1;
	int currentDepth = h;
	while (!foundLeaf) {
		printf ("%d %d %d\n", 2, currentNode, currentDepth);
		flush (std::cout);
		scanf ("%d", &node);
		if (node == -1) exit(0);
		if (node != 0) {
			currentNode = node;
			foundLeaf = true;
		}
		currentDepth++;
		numQ++;
	}
	// currentNode is a leaf node
	int distance = -1;
	while (distance != 0 && numQ < 2 * h + 1) {
		printf ("%d %d\n", 1, currentNode);
		flush (std::cout);
		scanf ("%d", &distance);
		if (distance == -1) exit(0);
		if (distance == 0) break;
		printf ("%d %d %d\n", 2, currentNode, distance);
		flush (std::cout);
		scanf ("%d", &currentNode);
		if (currentNode == -1) exit(0);
		numQ += 2;
	}
	printf ("3 %d\n", currentNode);
	flush (cout);
	scanf ("%d", &node);
	if (node == -1) {
		exit(0);
	}
}

int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
