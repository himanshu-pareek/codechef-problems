#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

pair < pair< lli, lli > , pair < lli, lli > > s1, s2;
pair < lli, lli > temp;

lli compare(pair < pair< lli, lli > , pair < lli, lli > > &s)
{
	if(s.f.f == s.s.f)
		{
			if(s.s.s < s.f.s)
				{
					temp = s.s;
					s.s = s.f;
					s.f = temp;
				}
		}
	else
		{
			if(s.s.f < s.f.f)
				{
					temp = s.s;
					s.s = s.f;
					s.f = temp;
				}
		}

	return 0;
}

int main()
	{
		int t;
		bool ans, col1, col2;
		lli diff1, diff2;

		cin >> t;

		while(t--)
			{
				ans = 0;

				cin >> s1.f.f >> s1.f.s >> s1.s.f >> s1.s.s;
				cin >> s2.f.f >> s2.f.s >> s2.s.f >> s2.s.s;

				compare(s1);
				compare(s2);
				
				//cout << " " << s1.f.f << " " << s1.f.s << " " << s1.s.f << " " << s1.s.s << endl;
				//cout << " " << s2.f.f << " " << s2.f.s << " " << s2.s.f << " " << s2.s.s << endl;

				if(s1.f.s == s1.s.s && s2.f.s == s2.s.s && s1.f.s == s2.s.s)
					{
						diff1 = abs(s1.s.f - s1.f.f) + abs(s2.f.f - s2.s.f) + 2;
						diff2 = max(abs(s2.s.f - s1.f.f), abs(s2.f.f - s1.s.f)) + 1;

						if(diff1 > diff2)
							ans = 1;
					}

				if(s1.f.f == s1.s.f && s2.f.f == s2.s.f && s1.f.f == s2.s.f)
					{
						diff1 = abs(s1.s.s - s1.f.s) + abs(s2.f.s - s2.s.s) + 2;
						diff2 = max(abs(s2.s.s - s1.f.s), abs(s2.f.s - s1.s.s)) + 1;

						if(diff1 > diff2)
							ans = 1;
					}

				if(s1.f.s == s1.s.s && s2.f.f == s2.s.f)
					{
						if(s1.s.f == s2.f.f && (s1.f.s == s2.f.s || s1.f.s == s2.s.s))
							ans = 1;
						if(s1.f.f == s2.f.f && (s1.f.s == s2.f.s || s1.f.s == s2.s.s))
							ans = 1;
					}

				if(s2.f.s == s2.s.s && s1.f.f == s1.s.f)
					{
						if(s2.s.f == s1.f.f && (s2.f.s == s1.f.s || s2.f.s == s1.s.s))
							ans = 1;
						if(s2.f.f == s1.f.f && (s2.f.s == s1.f.s || s2.f.s == s1.s.s))
							ans = 1;
					}

				if(ans)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}

		return 0;
	}
