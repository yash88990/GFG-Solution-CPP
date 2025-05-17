//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

void fizzBuzz(int number) {
    // Write your code here.
    if(number % 3 == 0 && number % 5 == 0)cout<< "FizzBuzz"<<endl;
    else if( number % 3 == 0)cout<< "Fizz"<<endl;
    else if(number % 5 == 0)cout<< "Buzz"<<endl;
    else cout<<number<<endl;
}


//{ Driver Code Starts.
    
int main() {
	
	int t; cin>>t;
	while(t--){
	    int number; cin>>number;
        fizzBuzz(number);
	
cout << "~" << "\n";
}
	
}
// } Driver Code Ends