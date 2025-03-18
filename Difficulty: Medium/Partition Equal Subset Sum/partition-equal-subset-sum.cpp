//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // If total sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = arr.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true; // A subset with sum 0 is always possible

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num]; // Include the current number if possible
            }
        }

        return dp[target];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends