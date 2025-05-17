//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  void solve(int current, vector<int>& result, int original, bool reverse) {
        result.push_back(current);
        if (current <= 0)  reverse = true;
        if (current == original && reverse)  return;
        if (reverse)
            solve(current + 5, result, original, reverse);
        else 
            solve(current - 5, result, original, reverse);
    }
    
    vector<int> pattern(int N) {
        vector<int> result;
        solve(N, result, N, false);
        return result;
    }
    
    
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends