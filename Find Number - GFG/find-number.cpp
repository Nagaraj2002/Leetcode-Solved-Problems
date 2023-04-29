//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        long long ans = 0;
        int arr[5] = {9, 1, 3, 5, 7};
        string s;
        long long t = n, mul = 1;
        while(t)
        {
            ans += mul * arr[t%5];
            mul *= 10;
            if(t%5 == 0) --t;
            t /= 5;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends