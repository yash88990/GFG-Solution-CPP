//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<string> invIsoTriangle(int N) {
        // code here
         vector<string>stars;
        
        for(int row = 1; row<=N; row++){
            for(int col = 1; col<row; col++){
                cout<<" ";
            }
           for(int col = 1; col <= 2*(N-row)+1; col++){
               cout<<"*";
           }
            for(int col = 1; col<row; col++){
                cout<<" ";
            }
            cout<<endl;
        }
        return stars;
    
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.invIsoTriangle(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends