//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<string> findThePattern(int N) {
        // code here
         int n=N;
        char k ='A';
        for(int i =1;i<=n;i++)
        {
            for(int j =1;j<=n;j++)
            {
                if(i==1||i==n)
                {
                    cout<<k++;
                }
                else if(j!=1&&j!=n)
                {
                    cout<<"$";
                }
                else
                {
                    cout<<k++;
                }
                
            }
        cout<<endl;
        }
    
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
        vector<string> v = ob.findThePattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends