//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:

int maxLength(string& str) {
    // Stack to store indices of '('
    stack<int> stk;
    // Initialize result to store the maximum length
    int max_len = 0;
    
    // Push -1 to the stack to handle edge case for first valid substring
    stk.push(-1);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            // Push the index of '(' onto the stack
            stk.push(i);
        } else {
            // Pop the top element (index of last '(' or boundary)
            stk.pop();
            
            // Check if stack is not empty
            if (!stk.empty()) {
                // Calculate the length of the valid substring
                max_len = max(max_len, i - stk.top());
            } else {
                // If stack is empty, push the current index as a new boundary
                stk.push(i);
            }
        }
    }
    
    return max_len;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends