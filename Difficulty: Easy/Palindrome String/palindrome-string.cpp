class Solution {
  public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string& s) {
        // code here
        string originals = s;
        int st = 0 , e = s.length() - 1;
        while(st <  e){
            swap(s[st++] , s[e--]);
        }
        return originals == s;
        
    }
};