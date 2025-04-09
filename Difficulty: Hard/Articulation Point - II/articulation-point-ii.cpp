//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    vector<int> adj[V];
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<bool> visited(V, false), isArticulation(V, false);
    int time = 0;

    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                dfs(v);

                low[u] = min(low[u], low[v]);

                // Case 1: root with 2+ children
                if (parent[u] == -1 && children > 1)
                    isArticulation[u] = true;

                // Case 2: non-root with low[v] >= disc[u]
                if (parent[u] != -1 && low[v] >= disc[u])
                    isArticulation[u] = true;
            }
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };

    // In case of disconnected graph
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    vector<int> result;
    for (int i = 0; i < V; i++) {
        if (isArticulation[i])
            result.push_back(i);
    }

    if (result.empty())
        return {-1};
    return result;
}

};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends