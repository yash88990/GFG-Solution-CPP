//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int capacity , vector<int> &value, vector<int> &weight , int index, vector<vector<int>> &dp){
        //base case 
        if(index == 0){
            if(weight[index] <= capacity)return value[index];
            else return 0;
        }
        if(dp[index][capacity] != -1)return dp[index][capacity];
        int include = 0 ;
        if(weight[index] <= capacity)
            include = value[index] + solve(capacity - weight[index] , value , weight , index -1 , dp);
        int exclude = 0 + solve(capacity , value , weight , index-1 , dp);
        dp[index][capacity] = max(include , exclude);
        return dp[index][capacity];
   
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n , vector<int>(W + 1 , -1));
        return solve(W , val , wt , n-1 , dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends