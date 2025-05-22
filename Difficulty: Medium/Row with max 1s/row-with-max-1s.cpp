// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int rowindex = -1 ;
        int j = m-1;
        for(int i = 0 ; i < n ; i++ ){
            while(j >= 0  && arr[i][j] == 1 ){
                j--;
                rowindex = i ;
            }
        }
        return rowindex ;
    }
};
