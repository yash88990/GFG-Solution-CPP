//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void printDiamond(int n) {
        // Top half
        for (int i = 1; i <= n; i++) {
            // Print leading spaces
            for (int j = 1; j <= n - i; j++) {
                cout << " ";
            }
            // Print stars with space
            for (int j = 1; j <= i; j++) {
                cout << "*";
                if (j != i) cout << " ";
            }
            cout << endl;
        }

        // Bottom half
        for (int i = n; i >= 1; i--) {
            // Print leading spaces
            for (int j = 1; j <= n - i; j++) {
                cout << " ";
            }
            // Print stars with space
            for (int j = 1; j <= i; j++) {
                cout << "*";
                if (j != i) cout << " ";
            }
            cout << endl;
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
        ob.printDiamond(n);
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends