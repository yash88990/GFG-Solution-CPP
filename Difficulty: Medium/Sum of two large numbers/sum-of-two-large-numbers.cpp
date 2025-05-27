// User function template for C++
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        // Ensure s1 is the longer string
        if (s1.length() < s2.length())
            swap(s1, s2);
        
        string result = "";
        int n1 = s1.length(), n2 = s2.length();
        int carry = 0;

        int i = n1 - 1, j = n2 - 1;

        while (j >= 0) {
            int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
            i--, j--;
        }

        while (i >= 0) {
            int sum = (s1[i] - '0') + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
            i--;
        }

        if (carry)
            result.push_back(carry + '0');

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int pos = 0;
        while (pos < result.size() - 1 && result[pos] == '0')
            pos++;

        return result.substr(pos);
    }
};
