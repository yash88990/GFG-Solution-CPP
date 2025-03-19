//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int maxProfit(vector<int>& prices, int k) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
    for (int t = 1; t <= k; t++) {
        int maxDiff = -prices[0];  // Stores max(dp[t-1][m] - prices[m])
        for (int d = 1; d < n; d++) {
            dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff);
            maxDiff = max(maxDiff, dp[t-1][d] - prices[d]);
        }
    }
    
    return dp[k][n-1];
}

};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends