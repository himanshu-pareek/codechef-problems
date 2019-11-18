#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double MAX_SCORE = 1e7;

template < typename T >
void printVector (const vector < T > & vec) {
    for (const T t : vec) {
        cout << t << " ";
    }
    cout << endl;
}

// ll power ()

bool isVowel (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool processString (string & s, vector < int > & freq, vector < int > & count) {
    const int n = s.size();
    // cout << s << " => " << n << endl;
    bool flag = true;
    for (int i = 0; i < n - 2; i++) {
        if (flag && !isVowel (s[i])) {
            if (!isVowel (s[i + 1]) || !isVowel (s[i + 2])) {
                flag = false;
            }
        }
        // cout << "Here" << endl;
        count[s[i] - 'a'] = 1;
        freq[s[i] - 'a']++;
    }
    if (n >= 2) {
        if (!isVowel(s[n - 2]) && !isVowel (s[n - 1])) {
            flag = false;
        }
        count[s[n-2] - 'a'] = 1; count[s[n - 1] - 'a'] = 1;
        freq[s[n-2] - 'a']++; freq[s[n - 1] - 'a']++;
    }
    // printVector (freq); printVector (count);
    return flag;
}

void solve () {
    int L;
    scanf ("%d", &L);
    int M = 0, N = 0; string s;
    vector < int > countA (26, 0), freqA (26, 0), countB (26, 0), freqB (26, 0);
    for (int i = 0; i < L; i++) {
        cin >> s;
        // cout << s << endl;
        vector < int > count (26, 0), freq (26, 0);
        bool b = processString (s, freq, count);
        // printVector (count);
        // printVector (freq);
        if (b) {
            M++;
            for (int i = 0; i < 26; i++) {
                countA[i] += count[i];
                freqA[i] += freq[i];
            }
        } else {
            N++;
            for (int i = 0; i < 26; i++) {
                countB[i] += count[i];
                freqB[i] += freq[i];
            }
        }
    }
    map < int, int > countPow;
    // printVector (countA);
    // printVector (freqA);
    // printVector (countB);
    // printVector (freqB);
    for (int i = 0; i < 26; i++) {
        if (countA[i] > 0) {countPow[countA[i]]++;}
        if (freqA[i] > 0) {countPow[freqA[i]] -= M;}
        if (countB[i] > 0) {countPow[countB[i]]--;}
        if (freqB[i] > 0) {countPow[freqB[i]] += N;}
    }
    // cout << "M = " << M << " " << "N = " << N << endl;
    // for (map < int, int > :: iterator it = countPow.begin(); it != countPow.end(); it++) {
    //     cout << (it -> first) << " => " << (it -> second) << endl;
    // }

    vector < pair < int , int > > vec;
    for (map < int, int > :: iterator it = countPow.begin(); it != countPow.end(); it++) {
        vec.push_back ({it -> second, it -> first});
    }
    sort (vec.begin(), vec.end());
    double answer = 1.0;
    double logx = 0.0;
    for (pair < int, int > p : vec) {
        // cout << p.first << " => " << p.second << endl;
        logx += (double) p.first * log10 (p.second);
        // answer *= pow (p.second, p.first);
        // if (answer > MAX_SCORE) {
        //     printf ("Infinity\n");
        //     return;
        // }
    }
    if (logx > 7) {
        printf ("Infinity\n");
        return;
    }
    answer = pow (10, logx);
    printf ("%.7f\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        // cout << "--------------" << endl;
        solve ();
    }
}
