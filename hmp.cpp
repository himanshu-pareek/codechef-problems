#include<bits/stdc++.h>
using namespace std;

bool check(int,int,int);

const int dx[] = {-1, 1, 0,  0};
const int dy[] = { 0, 0, 1, -1};

inline bool inside(int i, int j, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;

    //int i,j;

    int matrix[n][n];

    //Taking input of matrix
    for(int i = 0; i < n;i++){
      for(int j = 0; j < n; j++){
        cin >> matrix[i][j];
      }
    }
    set<pair<int,pair<int, int> > > weightVertex;      //weight, vertex
    vector <vector <int> > distance(n, vector <int>(n, INT_MAX));
    
    pair <int, int> source;
    source.first = 0;
    source.second = 0;
    distance[0][0] = matrix[0][0];
    
    weightVertex.insert(make_pair(distance[0][0], source));
    

    /* Looping till all shortest distance are finalized 
       then setds will become empty */

     while(weightVertex.empty() == false){
      cout << "ffsdf" << endl;
        // The first vertex in Set is the minimum distance 
        // vertex, extract it from set. 
       pair<int, pair<int, int> > temp = *(weightVertex.begin());
       int ix = temp.second.first;
       int jy = temp.second.second;
       int cur = temp.first;
       if (ix == n - 1 && jy == n - 1) {
           break;
       }
       weightVertex.erase(weightVertex.find(temp));
      cout << "fdfsdgsfgfg" << endl;

       cout << "ix = " << ix << ", iy = " << jy << endl;
       for (int i = 0; i < 4; i++) {
           int x = ix + dx[i];
           int y = jy + dy[i];
           if (inside(x, y, n)) {
               cout << "x = " << x << ", y = " << y << endl;
               int wgt = matrix[x][y];
               int next = distance[x][y];
               if (cur + wgt < next) {

				if (weightVertex.find (make_pair(next, make_pair(x, y))) != weightVertex.end()) {
					weightVertex.erase(weightVertex.find(make_pair(next, make_pair(x, y))));
				}
                 
                 distance[x][y] = cur + wgt;
                 weightVertex.insert(make_pair(distance[x][y], make_pair(x, y)));
               }
           } else {
           	cout << x << " and " << y << " are not valid" << endl;
           }
       }
     }
     
     cout << distance[n - 1][n - 1] << endl;
  }
}
