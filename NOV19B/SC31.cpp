#include <iostream>
#include <stdio.h>
using namespace std;

void solve () {
    int N; string s;
    scanf ("%d", &N);
    int count[10] = {0};
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == '1') {
                count[j] = 1 - count[j];
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        answer += count[i];
    }
    printf ("%d\n", answer);
}

int main() {
    int T;
    scanf ("%d", &T);
    while (T--) {
        solve();
    }
}
