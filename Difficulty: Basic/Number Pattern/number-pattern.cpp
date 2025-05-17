//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
    vector<string> numberPattern(int N)
    {
        // Write Your Code 
        vector<string>S;
        
        for(int i=1;i<=N;i++){
            string s="";
            int count=0;
            for(int j=1;j<=i;j++){
                count++;
                s=s+to_string(count);
            }
            for(int k=i;k>1;k--){
                count--;
                s=s+to_string(count);
            }
        S.push_back(s);
        }
        return S;
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
        vector<string> res = ob.numberPattern(N);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends