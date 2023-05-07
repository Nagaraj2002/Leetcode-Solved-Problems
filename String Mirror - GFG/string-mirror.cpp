//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
           string res;
        res=str[0];
        for(int i=1; i<str.length();i++){
            if(str[i-1]>str[i]) res+=str[i];
            else if(i>1 && str[i-1]==str[i]) res+=str[i];
            else break;
        }
       
        string temp = res;
        reverse(res.begin(),res.end());
        return (temp+res);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends