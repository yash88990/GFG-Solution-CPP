//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

int countDigits(int n) {

    // write your code here
    int count = 0;
    while( n != 0){
        int digit = n % 10;
        count++;
        n /= 10;
    }
    return count;
    // return number of digits in n
}


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << countDigits(n);
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends