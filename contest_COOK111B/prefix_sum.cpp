#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	int n,q;
	cin>>n >> q;
	vector < int > a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	vector <int> p(n);
	p[0] = a[0];
	for (int i = 1; i<n; i++) {
		p[i] = p[i-1] + a[i];
	}
	int sum;
	while(q--){
		cin >> l >> r;
		l--;
		r--;
		sum=p[r]-p[l]+a[l];
		int avg = sum/(r-l+1);
		cout >> avg;
	}

	return 0;
}
