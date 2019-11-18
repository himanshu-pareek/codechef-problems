#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void printMat (vector < vector < int > > &mat) {
    for (vector < int > vec : mat) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}

void printVector (vector < int > &vec) {
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl << "-----------------------------" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
    	// cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        int n, k, d, x;
        cin >> n >> k >> d;
        std::vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // printVector (a);
        std::vector<vector <int> > obstacles (2);
        for (int i = 0; i < n; i++) {
            cin >> x;
            obstacles[x - 1].push_back (a[i]);
        }
        obstacles[0].push_back(k);
        obstacles[1].push_back(k);
        // printMat (obstacles);
        pair < int, int > pointer = {0, 0};
        if (obstacles[0].empty() || obstacles[1].empty()) {
            cout << k << endl;
            continue;
        }
        int currentLane = obstacles[0][pointer.first] > obstacles[1][pointer.second];
        int distance = 0;
        bool firstTime = true;
        while (pointer.first < obstacles[currentLane].size() && pointer.second < obstacles[1 - currentLane].size()) {
            // cout << "first: " << pointer.first << ", second: " << pointer.second << ", distance: " << distance << ", currentLane: " << currentLane << endl;
            // printVector (obstacles[currentLane]);
            // printVector (obstacles[1 - currentLane]);
            if (distance >= obstacles[currentLane][pointer.first]) {
                distance = obstacles[currentLane][pointer.first];
                break;
            }
            swap (pointer.first, pointer.second);
            currentLane = 1 - currentLane;
            while (pointer.second < obstacles[1 - currentLane].size() && obstacles[1 - currentLane][pointer.second] < obstacles[currentLane][pointer.first]) {
                pointer.second++;
            }
            // pointer.second;
            if (firstTime) {
                distance = obstacles[1 - currentLane][pointer.second - 1] + 1;
                firstTime = false;
            } else {
                distance = max (distance + d, obstacles[1 - currentLane][pointer.second - 1] + 1);
            }
            
        }
        cout << distance << endl;
    }
}
