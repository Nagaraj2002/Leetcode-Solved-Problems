//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++
class Solution{
    public:
    long long mod = 1000000007;
    long long dp[1001][1001];
    long long binpow(long long x,long long y){
        long long ans = 1LL;
        while(y){
            if(y & 1LL){
                ans *= x;
            }
            x = (x * x);
            y >>= 1LL;
        }
        return ans;
    }
    
    long long helper(int target,int x,int i){
        long long p = pow(i,x);
        if(target == 0)return 1;
        if(p > target)return 0;
        if(dp[i][target] != -1)return dp[i][target];
        long long take = helper(target-p,x,i+1);
        long long not_take = helper(target,x,i+1);
        return dp[i][target] = (take + not_take) % mod;
    }
    int numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        return helper(n,x,1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends