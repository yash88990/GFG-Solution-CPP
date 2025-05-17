//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int binaryToDecimal(string &b) {
        int ans = 0;
        int i = 0; // position from right (LSB)

        int n = b.length() - 1; // Start from the rightmost bit

        while (n >= 0) {
            int digit = b[n] - '0'; // Convert char to int

            if (digit == 1) {
                ans += pow(2, i);
            }

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