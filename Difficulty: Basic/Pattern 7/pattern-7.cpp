//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i = 1 ; i <= n ; i++){
            //space print 
            for(int j = 1 ; j <= n-i ; j++)cout<<" ";
            //print start
            for(int j = 1 ; j < 2 * i ; j++)cout<<"*";
            cout<<endl;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends