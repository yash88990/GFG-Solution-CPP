//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

int getMaxArea(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    
    // Step 1: Compute left boundaries
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        while (j >= 0 && arr[j] >= arr[i]) {
            j = left[j];  // Jump directly to previous smaller
        }
        left[i] = j;
    }

    // Step 2: Compute right boundaries
    for (int i = n - 1; i >= 0; i--) {
        int j = i + 1;
        while (j < n && arr[j] >= arr[i]) {
            j = right[j];  // Jump directly to next smaller
        }
        right[i] = j;
    }

    // Step 3: Compute max area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, arr[i] * width);
    }

    return maxArea;
}




};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends