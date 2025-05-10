//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> first_occurrence; // prefix_sum -> first index
        int max_len = 0;
        int prefix_sum = 0;

        for (int i = 0; i < n; i++) {
            // Convert to +1 or -1 based on condition
            int val = (arr[i] > k) ? 1 : -1;
            prefix_sum += val;

            if (prefix_sum > 0) {
                // Entire subarray from 0 to i is valid
                max_len = i + 1;
            } else {
                // Check if prefix_sum - 1 was seen before
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }

            // Store first occurrence of this prefix sum
            if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
                first_occurrence[prefix_sum] = i;
            }
        }

        return max_len;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends