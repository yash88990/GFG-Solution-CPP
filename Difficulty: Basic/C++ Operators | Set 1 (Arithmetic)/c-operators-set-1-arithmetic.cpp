//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> cppOperators(int A, int B) {
        // code here
        int add =  A + B;
        int mul = A * B;
        int div = 0 ;
        int sub = abs(A - B);
        if( A > B )div = A / B;
        else div = B/A;
        
        vector<int>ans;
        ans.push_back(add );
        ans.push_back(mul );
        ans.push_back(sub );
        ans.push_back(div );
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B;
        cin >> A >> B;
        Solution ob;
        vector<int> ans = ob.cppOperators(A, B);
        for (int u : ans) cout << u << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends