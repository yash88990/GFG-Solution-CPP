//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int timer;
    vector<int> tin, low;
    vector<bool> visited;
    vector<vector<int>> adj;
    vector<pair<int, int>> bridges;

    void dfs(int u, int parent) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Build the graph
        adj.resize(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Initialize
        timer = 0;
        tin.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);

        // Step 3: DFS to find bridges
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        // Step 4: Check if (c, d) is a bridge
        for (auto &b : bridges) {
            // Since the graph is undirected, check both directions
            if ((b.first == c && b.second == d) || (b.first == d && b.second == c)) {
                return true;
            }
        }

        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends