//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int ans = 0;
        int originalnum = n;
        while( n != 0){
            int digit = n % 10;
            ans += pow(digit , 3);
            n /= 10;
        }
        if(originalnum == ans)return true;
        else return false;
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
        bool flag = ob.armstrongNumber(n);
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends