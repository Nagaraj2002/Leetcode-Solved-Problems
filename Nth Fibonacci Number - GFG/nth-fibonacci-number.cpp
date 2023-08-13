//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if(n<3) return 1;
        n-=2;
        int a=1,b=1;
        while(n--){
            b%=1000000007;
            a%=1000000007;
            int t=b;
            b+=a;
            a=t;
        }
        return b%1000000007;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends