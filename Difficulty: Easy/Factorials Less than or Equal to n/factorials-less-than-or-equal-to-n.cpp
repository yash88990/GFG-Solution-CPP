//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

void helper(long long i, long long fact, long long n, vector<long long> &ans) {
    if (fact > n) return; 
    ans.push_back(fact); 
    helper(i + 1, fact * (i + 1), n, ans); 
}

vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    helper(1, 1, n, ans); 
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends