//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;

        // Loop through each bit position
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            int x = (1 << i); // bitmask for current bit position

            for (int num : arr) {
                if (num & x) {
                    sum++;
                }
            }

            // If the sum is not divisible by 3, this bit is set in the unique number
            if (sum % 3 != 0) {
                result |= x;
            }
        }

        return result;
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
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends