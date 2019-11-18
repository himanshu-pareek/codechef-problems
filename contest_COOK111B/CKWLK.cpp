#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int T; ll N;
	cin >> T;
	while (T--) {
		cin >> N;
		int count10 = 0;
		while (N % 10 == 0) {
			N /= 10;
			count10++;
		}
		int count2 = 0;
		while (N % 2 == 0){
			N /= 2;
			count2++;
		}
		if (N > 1 || count10 < count2) cout << "No";
		else cout << "Yes";
		cout << endl;
	}
	return 0;
}

