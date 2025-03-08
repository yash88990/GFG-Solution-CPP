//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int expandaroundcenter(string& s , int left , int right ){
      while(left >= 0 && right < s.size() && s[left] == s[right]){
          left--;
          right++;
      }
      return right - left - 1 ;
  }
    string longestPalindrome(string& s) {
        // code here
        if(s.empty()) return "";
        int n = s.size();
        int start = 0 , max_length = 1;
        for(int i = 0 ; i < n ; i++){
            //odd-length palindrome 
            int length1 = expandaroundcenter(s , i , i);
            //even palindrome 
            int length2 = expandaroundcenter(s , i , i + 1);
            int length = max(length1 , length2);
            if(length > max_length){
                max_length = length;
                start = i - ( length - 1 ) / 2 ;
            }
        }
        return s.substr(start , max_length);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends