#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

void max_self (ll & a, ll b) {
	if (a < b) a = b;
}

template < typename T >
void printMat (vector < vector < T > > & mat) {
	for (vector < T > vec : mat) {
		for (T x : vec) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solve () {
	int n;
	scanf ("%d", &n);
	vector < ll > d (n);
	for (ll & x : d) scanf ("%lld", & x);
	ll localMax = 0, globalMax = INT_MIN;
	ll localMin = 0, globalMin = INT_MAX;
	vector < vector < ll > > presuf (4, vector < ll > (n));
	for (int i = 0; i < n; i++) {
		localMax = max (localMax + d[i], d[i]);
		globalMax = max (globalMax, localMax);
		localMin = min (localMin + d[i], d[i]);
		globalMin = min (globalMin, localMin);
		presuf[0][i] = globalMax;
		presuf[1][i] = globalMin;
	}
	
	localMax = localMin = globalMax = globalMin = 0;
	globalMax = INT_MIN;
	globalMin = INT_MAX;
	for (int i = n - 1; i >= 0; i--) {
		localMax = max (localMax + d[i], d[i]);
		globalMax = max (globalMax, localMax);
		localMin = min (localMin + d[i], d[i]);
		globalMin = min (globalMin, localMin);
		presuf[2][i] = globalMax;
		presuf[3][i] = globalMin;
	}
	
	//printMat (presuf);
	
	ll answer = 0;
	for (int i = 0; i < n - 1; i++) {
		max_self (answer, abs (presuf[0][i] - presuf[3][i + 1]));
		max_self (answer, abs (presuf[1][i] - presuf[2][i + 1]));
	}
	
	printf ("%lld\n", answer);
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		solve ();
	}
	return 0;
}

//gcloud compute --project=qwiklabs-gcp-00-29907832f3d6 networks create managementnet --subnet-mode=custom

//gcloud compute --project=qwiklabs-gcp-00-29907832f3d6 networks subnets create managementsubnet-us --network=managementnet --region=us-central1 --range=10.130.0.0/20

//gcloud compute --project=qwiklabs-gcp-00-29907832f3d6 firewall-rules create managementnet-allow-icmp-ssh-rdp --direction=INGRESS --priority=1000 --network=managementnet --action=ALLOW --rules=tcp:22,tcp:3389,icmp --source-ranges=0.0.0.0/0

//gcloud compute instances create privatenet-us-vm --zone=us-central1-c --machine-type=f1-micro --subnet=privatesubnet-us

