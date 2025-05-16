//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        int first = 0 ;
        int second = 1;
        int count = 2;
        if( n <= 1)return n;
        while(count <= n){
            int next = first + second;
            first = second ;
            second = next;
            count++;
        }
        return second;
        
        
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
        cout << ob.nthFibonacci(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends