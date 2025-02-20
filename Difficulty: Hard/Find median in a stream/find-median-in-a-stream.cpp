//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
vector<double> getMedian(vector<int> &arr) {
    vector<double> medians;
    priority_queue<int> left; // Max heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // Min heap (stores larger half)

    for (int num : arr) {
        // Step 1: Insert into appropriate heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Step 2: Balance heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        // Step 3: Compute median
        if (left.size() > right.size()) {
            medians.push_back(left.top());
        } else {
            medians.push_back((left.top() + right.top()) / 2.0);
        }
    }

    return medians;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends