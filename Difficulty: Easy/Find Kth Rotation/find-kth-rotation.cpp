// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int s =0 , e = arr.size() -1;
        while(s <= e){
            if(arr[s] <= arr[e])return s;
            int mid = s + ( e - s )/ 2;
            int next = (mid + 1 ) % n;
            if(arr[mid] <= arr[next] && arr[mid] < arr[(mid - 1 + n) % n] ){
                return mid;
            }
            
            if(arr[mid] <= arr[e])e = mid - 1;
            else if(arr[mid] >= arr[s])s = mid + 1 ;
        }
        return -1;
        
    }
};
