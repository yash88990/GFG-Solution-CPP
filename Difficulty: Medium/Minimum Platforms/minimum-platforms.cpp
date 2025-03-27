//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size() ;
        
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());

    int platformsNeeded = 1; // At least one platform is required
    int maxPlatformsNeeded = 1; // Maximum platforms needed at any time

    int arrIndex = 1, depIndex = 0; // Initialize pointers

    while (arrIndex < n && depIndex < n) {
        // If a train arrives before the departure of the previous train
        if (arr[arrIndex] <= dep[depIndex]) {
            platformsNeeded++; // Need a new platform
            maxPlatformsNeeded = max(maxPlatformsNeeded, platformsNeeded);
            arrIndex++; // Move to the next arrival time
        } else { // If a train departs before the arrival of the next train
            platformsNeeded--; // A platform is freed up
            depIndex++; // Move to the next departure time
        }
    }

    return maxPlatformsNeeded;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends