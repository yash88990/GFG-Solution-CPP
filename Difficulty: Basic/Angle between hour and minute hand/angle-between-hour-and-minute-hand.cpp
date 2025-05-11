//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int getAngle(int h, int m) {
        // Angle made by minute hand
        double minuteAngle = m * 6;

        // Angle made by hour hand
        double hourAngle = (h % 12) * 30 + (m / 60.0) * 30;

        // Calculate the absolute difference between the two angles
        double angle = abs(hourAngle - minuteAngle);

        // The smaller angle between the two hands
        angle = min(angle, 360 - angle);

        // Return the floor of the angle
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