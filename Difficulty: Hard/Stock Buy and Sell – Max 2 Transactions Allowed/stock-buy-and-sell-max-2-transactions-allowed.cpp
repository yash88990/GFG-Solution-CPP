//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0;

    vector<int> left(n, 0), right(n, 0);

    // Calculate max profit from left to right (First transaction)
    int min_price = prices[0];
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, prices[i]);
        left[i] = max(left[i - 1], prices[i] - min_price);
    }

    // Calculate max profit from right to left (Second transaction)
    int max_price = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        max_price = max(max_price, prices[i]);
        right[i] = max(right[i + 1], max_price - prices[i]);
    }

    // Find max profit by combining both transactions
    int max_profit = right[0];  // If we take only one transaction
    for (int i = 0; i < n; i++) {
        max_profit = max(max_profit, left[i] + right[i]);
    }

    return max_profit;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends