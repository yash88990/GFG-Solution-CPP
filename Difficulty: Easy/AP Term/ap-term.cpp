//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

int apTerm(int a, int d, int n) {
    // Complete the code above
    int ans = a + ( n - 1 ) *  d;

        // Complete the code above
        return ans;
}


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int a, d, n;
        cin >> a >> d >> n;
        cout << apTerm(a, d, n) << endl;
    }
}
// } Driver Code Ends