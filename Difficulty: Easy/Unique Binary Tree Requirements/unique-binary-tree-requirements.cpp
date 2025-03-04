//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution
{
public:
   bool isPossible(int a, int b) {
    // Valid unique tree constructions: (Preorder + Inorder) or (Postorder + Inorder)
    if ((a == 1 && b == 2) || (a == 2 && b == 1) ||  // Preorder + Inorder
        (a == 2 && b == 3) || (a == 3 && b == 2)) {  // Postorder + Inorder
        return true;
    }
    return false;  // Preorder + Postorder cannot uniquely determine a tree
}

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends