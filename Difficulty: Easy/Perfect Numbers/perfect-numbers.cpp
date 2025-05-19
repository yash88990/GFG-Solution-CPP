//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPerfectNumber(int n) {
        if (n <= 1) return false;
        int sum = 1;
        for(int i = 2; i * i <= n; ++i) {
            if(n % i == 0) {
                sum += i;
                if(i != n / i) sum += n / i;
            }
        }
        return sum == n;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;

        Solution ob;
        bool ans = ob.isPerfectNumber(N);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends