//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

string utility(int number) {
    // return the appropriate string
    switch(number){
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "Unknown";
    }
}


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int number;
        cin >> number;
        cout << utility(number) << endl;
    }
}
// } Driver Code Ends