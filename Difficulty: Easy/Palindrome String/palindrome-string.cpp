class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        string reversestr = s;
        reverse(reversestr.begin() , reversestr.end());
        return s == reversestr;
    }
};