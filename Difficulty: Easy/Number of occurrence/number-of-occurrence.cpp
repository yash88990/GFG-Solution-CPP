class Solution {
    private:
    int firstocc(vector<int> &arr ,int n ,int k){
    int ans = -1;
    int start = 0 , end = n- 1;
    while(start <= end){
        int mid = start + ( end - start) / 2;
        if(arr[mid] == k){
            ans = mid;
            end = mid - 1;
        }else if(arr[mid] < k){
            start = mid + 1;
        }
        else{
           end = mid - 1;
        }
    }
    return ans;
}
int lastocc(vector<int> &arr ,int n , int k){
    int ans = -1;
    int start = 0 , end = n- 1;
    while(start <= end){
        int mid = start + ( end - start) / 2;
        if(arr[mid] == k){
            ans = mid;
            start = mid + 1;
        }else if(arr[mid] < k){
            start = mid + 1;
        }
        else{
           end = mid - 1;
        }
    }
    return ans;
}
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int f = firstocc(arr ,n , target );
        int l = lastocc(arr , n , target);
        if(f == -1)return 0;
        return l - f + 1;
        
    }
};
