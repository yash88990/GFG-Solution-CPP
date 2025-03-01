//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> numstack;
        stack<string> strstack;
        string currentstring = "";
        int currentnum = 0;
        for(char c :  s){
            if(isdigit(c))
               currentnum  = currentnum * 10 + (c - '0');
             else if( c == '['){
                 numstack.push(currentnum);
                 strstack.push(currentstring);
                 currentnum = 0;
                 currentstring ="";
             }else if(c == ']'){
                 int k = numstack.top(); numstack.pop();
                 string prevstring = strstack.top() ; strstack.pop();
                 for(int i = 0 ; i < k ; i++){
                     prevstring += currentstring;
                 }
                 currentstring = prevstring;
             }else{
                 currentstring += c;
                 
             }
        }
        return currentstring;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends