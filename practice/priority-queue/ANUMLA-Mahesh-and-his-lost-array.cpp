#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

//int main ()
//{
  //std::multiset<int> mymultiset;
  //std::multiset<int>::iterator it;

  //// insert some values:
  //mymultiset.insert (40);                            // 40
  //for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60

  //it = mymultiset.find (40);
  //mymultiset.erase (it);

  //std::cout << "mymultiset contains:";
  //for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    //std::cout << ' ' << *it;
  //std::cout << '\n';

  //return 0;
//}

void solve () {
	int n;
	scanf ("%d", &n);
	vector < int > sums (1 << n);
	for (int & sum : sums) scanf ("%d", & sum);
	multiset < int > ms;
	for (int sum : sums) {
		if (sum != 0) {
			ms.insert (sum);
		}
	}
	vector < int > result;
	vector < int > currentSums;
	currentSums.push_back (0);
	for (int i = 0; i < n; i++) {
		int x = *ms.begin();
		// Insert into result
		result.push_back (x);
		int currsize = currentSums.size();
		for (int i = 0; i < currsize; i++) {
			int s = x + currentSums[i];
			// insert into currentSums
			currentSums.push_back (s);
			// remove from ms
			auto it = ms.find (s);
			ms.erase (it);
		}
	}
	for (int x : result) {
		printf ("%d ", x);
	}
	printf ("\n");
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
