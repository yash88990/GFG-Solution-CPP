//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string maxNum; // to keep track of the maximum number

    void solve(string& s, int k, int idx) {
        if (k == 0) return;

        int n = s.length();
        char maxDigit = s[idx];

        // Find the maximum digit from idx to end
        for (int i = idx + 1; i < n; i++) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        // If the current digit is already the max, no need to swap
        if (maxDigit != s[idx]) k--;

        for (int i = n - 1; i >= idx; i--) {
            if (s[i] == maxDigit) {
                swap(s[idx], s[i]);

                if (s.compare(maxNum) > 0) {
                    maxNum = s;
                }

                solve(s, k, idx + 1);
                swap(s[idx], s[i]); // backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        solve(s, k, 0);
        return maxNum;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends