//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
         int gcd = __gcd(a, b);  // Compute GCD using built-in function
         long long lcm = (1LL * a * b) / gcd;  // Compute LCM using formula
    
          return { (int)lcm, gcd }; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends