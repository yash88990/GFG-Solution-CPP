//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<string> pattern(string& s) {
        vector<string> a;
        for (int i = s.size(); i > 0; i--) {
            a.push_back(s.substr(0, i));
        }
        return a;
    }
};



//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<string> ans = ob.pattern(s);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends