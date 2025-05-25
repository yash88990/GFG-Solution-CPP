// User function template for C++

class Solution {
public:
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> ans;
        binarySearchHelper(arr, 0, arr.size() - 1, ans);
        sort(ans.begin(), ans.end()); // optional, for sorted output
        return ans;
    }

private:
    void binarySearchHelper(vector<int>& arr, int low, int high, vector<int>& ans) {
        if (low > high) return;

        int mid = low + (high - low) / 2;

        // Check if arr[mid] == index + 1
        if (arr[mid] == mid + 1) {
            ans.push_back(arr[mid]);
        }

        // Always explore both sides to find all such indices
        binarySearchHelper(arr, low, mid - 1, ans);
        binarySearchHelper(arr, mid + 1, high, ans);
    }
};
