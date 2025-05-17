//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> printPat(int n) {
        vector<int> result;
        
        for(int i = n; i >= 1; i--) {  // i is the row index
            for(int num = n; num >= 1; num--) {
                for(int count = 0; count < i; count++) {
                    result.push_back(num);
                }
            }
            result.push_back(-1); // end of current row
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        vector<int> ans = obj.printPat(n);

        // Print ans vector with space separation
        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends