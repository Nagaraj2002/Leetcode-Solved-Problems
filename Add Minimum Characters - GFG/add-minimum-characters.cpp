//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
              int c=0,n=str.length();
        int i=0,j=n-1;
        while(i<j){
            if(str[i]==str[j]){
                i++,j--;
            }
            else{
                c++;
                i=0,j=n-c-1;
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends