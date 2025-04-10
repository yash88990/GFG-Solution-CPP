//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        int totalCost = 0;
        int connected = 0;
        
        // Min-heap: pair<cost, house_index>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));

        while (connected < n) {
            pair<int, int> top = pq.top();
            pq.pop();
            int cost = top.first;
            int curr = top.second;

            if (visited[curr]) continue;

            visited[curr] = true;
            totalCost += cost;
            connected++;

            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dist = abs(houses[curr][0] - houses[i][0]) + abs(houses[curr][1] - houses[i][1]);
                    pq.push(make_pair(dist, i));
                }
            }
        }
        
        return totalCost;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends