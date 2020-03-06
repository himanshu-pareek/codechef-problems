#include <bits/stdc++.h>
using namespace std;
int fun() {
	static int num = 108;
	return --num%10;
}

int main() {
	//int start = 2, end = 7;
	//for 
	int sum = 0;
	for (int i = 100; i <= 1000; i++) {
		if (i % 14 == 0) {
			sum += i;
		}
	}
	cout << sum << endl;
	//int i = 4, j = 8;
	//printf ("%d, %d, %d\n", i|j&j|i, i|j&&j|i, i ^ j);
	//char s[] = {"ADAPTABLE AND INTELLIGENT"};
	//for (fun(); fun(); fun()) {
		//printf ("%c", s[fun()]);
	//}
	//getchar();
	//int x = 3;
	//cout << ((x << 2) + x + (x >> 1)) << endl;
	return 0;
}
	
