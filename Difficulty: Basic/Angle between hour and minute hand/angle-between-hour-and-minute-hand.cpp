//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getAngle(int h, int m) {
        // code here
        double minangle = m * 6;
        double hourangle = ( h % 12) * 30 + ( m /60.0) * 30;
        double angle = abs(minangle - hourangle);
        angle = min( 360 - angle , angle);
        return floor(angle);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m;

        cin >> h >> m;

        Solution ob;
        cout << ob.getAngle(h, m) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends