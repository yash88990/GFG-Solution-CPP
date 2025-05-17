//{ Driver Code Starts
#include <iostream>
using namespace std;

void printPattern(string s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	printPattern(s);
	cout<<endl;
	

cout << "~" << "\n";
}
	
	return 0;
}
// } Driver Code Ends


void printPattern(string s)
{
   int len = s.size();
   int pos = len/2;
   string str = "";
   while(len--)
   {
       if(pos == s.size())pos = 0;
       str += s[pos++];
       cout<<str<<"$ ";
   }
}