//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int maxPartitions(string &s) {
    int start = 0, count = 0;
    unordered_map<char, int> lastOccurrence;

    // Step 1: Store the last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        lastOccurrence[s[i]] = i;
    }

    // Step 2: Traverse the string to determine partitions
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
        end = max(end, lastOccurrence[s[i]]);  // Extend partition to the rightmost occurrence

        // When we reach the end of a partition, we count it
        if (i == end) {
            count++;
            start = i + 1;  // Move to next partition
        }
    }

    return count;
}

};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends