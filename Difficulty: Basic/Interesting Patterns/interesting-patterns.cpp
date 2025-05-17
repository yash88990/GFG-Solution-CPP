//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    vector<string> interestingPattern(int N) {
        int size = 2 * N - 1;
        vector<string> ans;
        
        for (int i = 0; i < size; i++) {
            string row = "";
            for (int j = 0; j < size; j++) {
                // Calculate minimum distance from edges
                int top = i;
                int left = j;
                int right = size - 1 - j;
                int bottom = size - 1 - i;
                int min_dist = min({top, left, right, bottom});
                
                // Value to print
                int val = N - min_dist;
                row += to_string(val);
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.interestingPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends