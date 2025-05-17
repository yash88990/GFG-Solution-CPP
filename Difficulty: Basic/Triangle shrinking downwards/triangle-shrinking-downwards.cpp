//{ Driver Code Starts
#include <bits/stdc++.h>
#include<string>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string triDownwards(string S) {
        string result = "";
        int n = S.length();
        
        for (int i = 0; i < n; ++i) {
            result += string(i, '.');       // i dots
            result += S.substr(i);          // substring from index i to end
        }
        
        return result;
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
        string ans=ob.triDownwards(S);
        
        for(int i=0 ; i<ans.length() ; i++)
        {
            cout<<ans[i];
            if((i+1)%S.length()==0)
                cout<<endl;
        }
        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends