//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size() , l = 0 , maxlen = 0 , startindex = 0;
        multiset<int> window;
        for(int i = 0 ; i < n ; i++){
            window.insert(arr[i]);
            while(*window.rbegin() - *window.begin() > x){
                window.erase(window.find(arr[l]));
                l++;
            }
            if(i - l + 1 > maxlen){
                maxlen =  i - l + 1;
                startindex = l;
            }
        }
        return vector<int>(arr.begin() + startindex , arr.begin() + startindex + maxlen);
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends