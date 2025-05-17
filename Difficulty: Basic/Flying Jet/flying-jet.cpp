//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution{
	public:
   	long long int Nth_mileSpeed(int n){
   	    if(n%2 == 1) return 1ll*pow(n/2+1,4);
   	    else  return 7ll*pow(3,n/2-1);
   	}    
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.Nth_mileSpeed(n);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends