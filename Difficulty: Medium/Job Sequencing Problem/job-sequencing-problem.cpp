//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:


class DisjointSet {
public:
    vector<int> parent;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;  // Initially, each slot is its own parent
    }

    int find(int s) {
        if (parent[s] == s) return s;
        return parent[s] = find(parent[s]);  // Path compression
    }

    void merge(int u, int v) {
        parent[u] = v;  // Union operation
    }
};

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<pair<int, int>> jobs;  // (profit, deadline) pair

    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // Sort jobs in descending order of profit
    sort(jobs.rbegin(), jobs.rend());

    // Find the maximum deadline
    int maxDeadline = *max_element(deadline.begin(), deadline.end());

    // Disjoint set to manage available slots
    DisjointSet ds(maxDeadline);

    int countJobs = 0, maxProfit = 0;

    for (auto &job : jobs) {
        int d = job.second;
        int availableSlot = ds.find(d);  // Find the latest available slot before or at d

        if (availableSlot > 0) {
            ds.merge(availableSlot, availableSlot - 1);  // Mark slot as used
            countJobs++;
            maxProfit += job.first;
        }
    }

    return {countJobs, maxProfit};
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends