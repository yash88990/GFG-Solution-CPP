//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int NthTerm(int n) {
        const int mod = 1e9 + 7;
        long long term = 2;  // a[1] = 2
        for (int i = 2; i <= n; i++) {
            term = (term * i) % mod;
            term = (term + 1) % mod;
        }
        return term;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends