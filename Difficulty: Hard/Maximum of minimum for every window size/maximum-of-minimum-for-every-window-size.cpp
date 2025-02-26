//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n), res(n, INT_MIN);

    stack<int> s;

    // Compute previous smaller elements
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        left[i] = s.empty() ? (i + 1) : (i - s.top());
        s.push(i);
    }

    // Clear stack to reuse for next smaller elements
    while (!s.empty()) s.pop();

    // Compute next smaller elements
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        right[i] = s.empty() ? (n - i) : (s.top() - i);
        s.push(i);
    }

    // Fill res[] where res[len] is the maximum minimum for window of size len
    for (int i = 0; i < n; i++) {
        int len = left[i] + right[i] - 1;
        res[len - 1] = max(res[len - 1], arr[i]);
    }

    // Fill missing values from right to left
    for (int i = n - 2; i >= 0; i--)
        res[i] = max(res[i], res[i + 1]);

    return res;
}


};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends