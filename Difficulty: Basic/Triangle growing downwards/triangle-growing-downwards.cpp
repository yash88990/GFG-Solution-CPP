//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
  public:
    void printTriangleDownwards(string str) {
        // Write Your Code here
          int n = str.length();
        
        for(int i=0; i<str.length(); i++)
        {
            int k = 0;
            for(int j=n-1; j>=0; j--)
            {
                if(i >= j)
                {
                    cout<<str[k];
                    k++;
                }
                else
                {
                    cout<<".";
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
        string str;
        cin >> str;

        Solution ob;
        ob.printTriangleDownwards(str);
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends