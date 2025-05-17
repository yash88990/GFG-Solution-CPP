//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    vector<string> yShapedPattern(int N) {
        // code here
        vector<string> v;
        for(int i=0;i<N/2;i++){
            for(int sp=0;sp<i;sp++){
                cout << " ";
            }
            for(int j=0;j<N+1-(2*i);j++){
                if(j==0 || j==N-(2*i)){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            for(int sp=0;sp<i;sp++){
                cout << " ";
            }
            cout << endl;
        }
        
        for(int i=0;i<N/2;i++){
            for(int sp=0;sp<N/2;sp++){
                cout << " ";
            }
            for(int j=0;j<1;j++){
                cout << "*";
            }
            for(int sp=0;sp<N/2;sp++){
                cout << " ";
            }
            cout << endl;
        }
        return v;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.yShapedPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends