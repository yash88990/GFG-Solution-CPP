//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
int longestSubarray(vector<int>& arr, int k) {
    int len = 0;
    int sum = 0;
    unordered_map<int, int> prefixSumMap;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];  
        if (sum == k) len = max(len, i + 1);
        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) 
            len = max(len, i - prefixSumMap[sum - k]);
        if (prefixSumMap.find(sum) == prefixSumMap.end()) 
            prefixSumMap[sum] = i;
    }
    return len;
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends