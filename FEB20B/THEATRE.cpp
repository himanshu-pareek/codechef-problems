#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
    int S = 0, T;
    cin >> T;
    vector < int > prices = {25, 50, 75, 100};
    while (T--) {
        vector < vector < int > > mat (4, vector < int > (4));
        int N, slot; char movie;
        cin >> N;
        while (N--) {
            cin >> movie >> slot;
            if (slot == 3) slot = 1;
            else if (slot == 6) slot = 2;
            else if (slot == 9) slot = 3;
            else slot = 0;
            mat[movie - 'A'][slot]++;
        }
        vector < int > movie_slots = {0, 1, 2, 3};
        int maxProfit = -400;
        do {
            vector < int > viewers;
            for (int mv = 0; mv < 4; mv++) {
                viewers.push_back (mat[mv][movie_slots[mv]]);
            }
            sort (viewers.begin(), viewers.end());
            int profit = 0;
            for (int i = 0; i < 4; i++) {
                if (viewers[i] == 0) {
                    profit -= 100;
                } else {
                    profit += prices[i] * viewers[i];
                }
            }
            maxProfit = max (maxProfit, profit);
        } while (next_permutation (movie_slots.begin(), movie_slots.end()));
        S += maxProfit;
        cout << maxProfit << endl;
    }
    cout << S << endl;
    return 0;
}

