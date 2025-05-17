//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

// Write the complete function returnValueFunction below
// This function should take n as a parameter
// return double of n
// code here
int returnValueFunction (int n ){
    return n * 2 ;
}



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << returnValueFunction(n) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends