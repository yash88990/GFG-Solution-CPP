class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int start = 0 , end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2 ;
            if(arr[mid] == k){
                ans = mid;
                end = mid -1;
            }
            else if(arr[mid] < k)start = mid + 1;
            else end = mid -1;
        }
        return (ans != -1) ? ans : -1;
    }
};