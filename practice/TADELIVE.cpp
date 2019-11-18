#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector < pair < int, int > > tips (n);
	for (int i = 0; i < n; i++) {
		cin >> tips[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> tips[i].second;
	}
	sort (tips.begin(), tips.end(), [&] (const pair < int, int > & p1, const pair < int, int > & p2) {
		return abs (p1.first - p1.second) > abs (p2.first - p2.second);
	});
	int answer = 0;
	for (pair < int, int > p : tips) {
		if (x && p.first >= p.second) {
			answer += p.first;
			x--;
		} else {
			answer += p.second;
			y--;
		}
	}
	cout << answer << endl;
	return 0;
}
