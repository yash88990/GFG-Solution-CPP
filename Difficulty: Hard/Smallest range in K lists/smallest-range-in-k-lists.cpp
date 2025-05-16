//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();

        // Min heap stores tuple: (value, list_index, element_index)
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];  // min heap based on value
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int currentMax = INT_MIN;

        // Initialize the heap with first element from each list
        for (int i = 0; i < k; i++) {
            minHeap.push({arr[i][0], i, 0});
            if (arr[i][0] > currentMax) currentMax = arr[i][0];
        }

        int minRange = INT_MAX;
        int start = -1, end = -1;

        // Process the heap
        while (true) {
            auto minElem = minHeap.top();
            minHeap.pop();

            int currentMin = minElem[0];
            int listIdx = minElem[1];
            int eleIdx = minElem[2];

            // Check if current range is smaller
            if (currentMax - currentMin < minRange) {
                minRange = currentMax - currentMin;
                start = currentMin;
                end = currentMax;
            }

            // Move to next element in this list
            if (eleIdx + 1 == n) {
                // We reached the end of one list, cannot cover all lists anymore
                break;
            }

            int nextVal = arr[listIdx][eleIdx + 1];
            minHeap.push({nextVal, listIdx, eleIdx + 1});

            // Update currentMax if needed
            if (nextVal > currentMax) currentMax = nextVal;
        }

        return {start, end};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends