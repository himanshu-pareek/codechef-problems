#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

#define BUG(x) if (DEBUG) cout << __LINE__ << ": " << #x << " = " << x << endl
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for(LET(it, (v).begin()); it != (v).end(); ++it)

typedef long long LL;

template <class T> inline int size(const T& c) {return (int) c.size();}
int rInt() {int nT = -1; scanf("%d", &nT); return nT;}

const int INF  = 1 << 30;

int main()
{
	int nTest = 1;
	for (int test = 1; test <= nTest; ++test) {
		int V = rInt(), E = rInt();
		vector < vector <int> > graph(V, vector <int> (V, 0));
		for (int i = 0; i < E; ++i) {
			int u = rInt(), v = rInt(), w = rInt();
			graph[u][v] = graph[v][u] = w;
		}
		for (int u = 0; u < V; ++u)
			graph[u][u] = INF;
		for (int k = 0; k < V; ++k)
			for (int u = 0; u < V; ++u)
				for (int v = 0; v < V; ++v)
					graph[u][v] = max(graph[u][v], min(graph[u][k], graph[k][v]));
		for (int u = 0; u < V; ++u) {
			for (int v = 0; v < V; ++v)
				if (u == v) printf("0 ");
				else printf("%d ", graph[u][v]);
			printf("\n");
		}
	}
	return 0;
}

// Powered by PhoenixAI
