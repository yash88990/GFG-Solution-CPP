class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> squares;

        // Store squares of all elements
        for (int i = 0; i < n; ++i) {
            squares.insert(arr[i] * arr[i]);
        }

        // Check for every pair (a, b) if a^2 + b^2 exists in the set
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if (squares.find(sum) != squares.end()) {
                    return true;
                }
            }
        }

        return false;
    }
};
