//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void printTriangle(int n) {
        // code here
        for(int i = 1 ; i <= n ; i++){
            int a = 1;
            for(int j = 1 ; j <= i ; j++){
                cout<<j<<" ";
                a++;
            }
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