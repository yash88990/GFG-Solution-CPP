//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends


class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n ==0)return 0;
        if(n==1)return arr[0];
        int prev2 = 0 , prev1 = arr[0];
        for(int i = 1 ; i < n ; i++){
            int loot = arr[i] + prev2;
            int skip = prev1;
            int curr = max(loot , skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends