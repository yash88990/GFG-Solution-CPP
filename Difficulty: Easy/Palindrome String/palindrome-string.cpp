class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
       string originalstr = s;
       reverse(s.begin() , s.end());
       return originalstr == s;
    }
};