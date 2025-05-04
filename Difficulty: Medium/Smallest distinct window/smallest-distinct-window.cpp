//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        unordered_set<char> uniqueChars(str.begin(), str.end());
        int distinctCount = uniqueChars.size();
        
        vector<int> freq(26, 0); // Frequency map for lowercase characters
        int minLen = str.length();
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < str.length(); ++right) {
            freq[str[right] - 'a']++;
            if (freq[str[right] - 'a'] == 1)
                count++; // New unique character added
            
            while (count == distinctCount) {
                minLen = min(minLen, right - left + 1);
                freq[str[left] - 'a']--;
                if (freq[str[left] - 'a'] == 0)
                    count--; // Unique character removed
                left++;
            }
        }
        
        return minLen;
    }
};



//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends