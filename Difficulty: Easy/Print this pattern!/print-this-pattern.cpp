//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
  public:
    void printPattern(int N)
    {
       
        for(int i=1;i<=2*N -1;i++)
        {
            int cnt = N;
            for(int j=1;j<=2*N -1;j++)
            {
                cout<<cnt;
                if(i>j)
                cnt--;
                
                if(i+j>=2*N)
                {
                    cnt++;
                }
            }
            cout<<endl;

        }
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        
        Solution ob;
        ob.printPattern(N);
        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends