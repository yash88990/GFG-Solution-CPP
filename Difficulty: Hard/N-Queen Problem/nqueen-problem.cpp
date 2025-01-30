//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> result;
  bool isSafe(vector<int> &board , int col , int row){
      for(int i = 0 ; i < row ; i++){
          if(board[i] == col || abs(board[i] - col) == abs(i - row)){
              return false;
          }
      }
      return true;
  }
  void solveQueen(vector<int> &board , int row , int n){
      if(row == n ){
          result.push_back(board);
          return;
      }
      for(int col = 1 ; col <= n ; col++){
          if(isSafe(board , col , row)){
              board[row] = col;
              solveQueen(board , row+1 , n);
          }
      }
     
  }
    vector<vector<int>> nQueen(int n) {
        // code here
        result.clear();
        vector<int> board(n,0);
        solveQueen(board , 0 , n );
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends