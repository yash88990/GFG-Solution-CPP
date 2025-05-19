//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int ans = 0 ; 
        int i = 0;
        int n = b.length() - 1;
        while( n >= 0){
            int digit = b[n] - '0';
            if(digit == 1)ans += pow(2 , i);
            i++;
            n--;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binaryToDecimal(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends