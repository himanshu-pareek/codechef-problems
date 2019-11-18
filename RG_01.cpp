#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int INFINITE = (1 << 30);
const int base = 15;

struct Edge {
    int u, v;
    int weight;
    Edge (int u, int v, int weight) {
        this -> u = u;
        this -> v = v;
        this -> weight = weight;
    }
};

struct UnionFind {
    vector < int > parent;
    vector < int > rank;

    UnionFind (int V) {
        parent.resize (V);
        rank.resize (V, 0);
    }

    void makeSet (int x) {
        parent[x] = x;
    }

    int find (int u) {
        return (parent[u] == u) ? u : (parent[u] = find (parent[u]));
    }

    void _union (int u, int v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

struct Graph {
    vector < vector < int > > adj;
    vector < vector < int > > cost;

    Graph (int V) {
        adj.resize (V);
        cost.resize (V, vector < int > (V, 0));
        for (int i = 0; i < V; i++) {
            cost[i][i] = INFINITE;
        }
    }

    void addEdge (int u, int v, int weight) {
        adj[u].push_back (v);
        adj[v].push_back (u);
        cost[u][v] = cost[v][u] = weight;
    }

    void solveBFS (vector < int > &dist, int source) {
        queue < int > q;
        dist[source] = (1 << 29);
        q.push (source);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == INFINITE) {
                    dist[v] = min (dist[u], cost[u][v]);
                    q.push (v);
                }
            }
        }
    }
};

struct Solver {
    int V, E;
    vector < vector < int > > graph;
    vector < vector < int > > score;

    inline int remainder (int x) {return (x & ((1 << base) - 1));}

    inline int quotient (int x) {return (x >> base);}

    void solveMST (vector < Edge* > &mst, vector < Edge* > &edges) {
        vector < Edge* > sortedEdges;
        vector < vector < Edge* > > firstPass (1 << base);
        vector < vector < Edge* > > secondPass (1 << base);

        for (Edge* edge : edges) {
            firstPass[remainder (edge -> weight)].push_back (edge);
        }
        // cout << "Here" << endl;
        for (int i = (int)firstPass.size() - 1; i >= 0; i--) {
            for (Edge* edge : firstPass[i]) {
                secondPass[quotient (edge -> weight)].push_back (edge);
            }
        }
        // cout << "Here1" << endl;

        for (int i = (int)secondPass.size() - 1; i >= 0; i--) {
            // cout << "i = " << i << ", size = " << secondPass[i].size() << ", Here2" << endl;
            for (int j = 0; j < (int)secondPass[i].size() - 1; j++) {
                // cout << "i = " << i << ", j = " << j << endl;
                sortedEdges.push_back (secondPass[i][j]);
            }
            // cout << i << " Here2" << endl;
        }

        
        UnionFind unionFind(V);

        for (int i = 0; i < V; i++) {
            unionFind.makeSet (i);
        }

        for (Edge* edge : sortedEdges) {
            int p = unionFind.find (edge -> u);
            int q = unionFind.find (edge -> v);
            if (p != q) {
                unionFind._union (p, q);
                mst.push_back (edge);
            }
        }
    }

    Solver (int V, vector < Edge* > &edges) {
        this -> V = V;
        this -> E = edges.size();
        vector < Edge* > mst;
        graph.resize (V, vector < int > (V, INFINITE));

        for (Edge* edge : edges) {
            graph[edge -> u][edge -> v] = edge -> weight;
            graph[edge -> v][edge -> u] = edge -> weight;
        }
        // cout << "Here" << endl;
        solveMST (mst, edges);
// cout << "Here" << endl;
        Graph G(V);

        for (Edge* edge : mst) {
            G.addEdge (edge -> u, edge -> v, edge -> weight);
        }

        score.resize (V, vector < int > (V, INFINITE));
        for (int i = 0; i < score.size(); i++) {
            G.solveBFS (score[i], i);
        }
    }

    int query (int i, int j) {
        return score[i][j];
    }

};

int main() {
    int T;
    T = 1;
    while (T--) {
        int V, E;
        cin >> V >> E;
        vector < Edge* > edges;
        edges.reserve ((V * (V - 1)) >> 1);
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back (new Edge (u, v, w));
        }
        
        Solver solve(V, edges);
        // cout << "Here" << endl;
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (u == v) cout << "0";
                else cout << solve.query (u, v);
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
