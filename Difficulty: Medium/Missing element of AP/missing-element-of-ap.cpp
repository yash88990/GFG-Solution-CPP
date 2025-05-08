//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return arr[0]; // Not enough to determine

        // Step 1: Find actual minimum common difference
        int d = INT_MAX;
        for (int i = 1; i < n; i++) {
            d = min(d, arr[i] - arr[i - 1]);
        }

        // Step 2: Binary search to find the break
        int low = 0, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid + 1] - arr[mid] != d) {
                return arr[mid] + d;
            }

            if (arr[mid] - arr[0] == mid * d) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Step 3: If no missing, return the next AP term
        return arr[n - 1] + d;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends