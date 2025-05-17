//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

int nthDay(int d, int n) {

    return ((d - n) % 7 + 7) % 7;
}


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t-- > 0) {
        int d, n;
        cin >> d >> n;
        cout << nthDay(d, n) << endl;
    }
}
// } Driver Code Ends