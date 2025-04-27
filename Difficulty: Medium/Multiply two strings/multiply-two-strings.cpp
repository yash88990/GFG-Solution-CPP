//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string multiplyStrings(string& s1, string& s2) {
        // Step 1: Handle signs
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }

        // Step 2: Remove leading zeros
        while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
        while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);
        
        // Step 3: Edge case
        if (s1 == "0" || s2 == "0") return "0";

        int n = s1.size(), m = s2.size();
        vector<int> result(n + m, 0);

        // Step 4: Multiply each digit
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Step 5: Build result string
        string ans = "";
        for (int num : result) {
            if (ans.empty() && num == 0) continue; // skip leading zeros
            ans += (num + '0');
        }

        if (isNegative) ans = "-" + ans;
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends