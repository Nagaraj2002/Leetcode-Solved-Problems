//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        //  int solve(int a, int b, int c) {
       if(a>=b and a>=c){
           int halfa=(a%2==0?a/2:a/2+1);
           int req=halfa-1;
            if(b+c>=req)
          return a+b+c;
       }
       if(b>=a and b>=c){
           int halfb=(b%2==0?b/2:b/2+1);
           int req=halfb-1;
           if(a+c>=req)
          return a+b+c;
       }
       if(c>=a and c>=b){
          int halfc=(c%2==0?c/2:c/2+1);
           int req=halfc-1;
        if(a+b>=req)
          return a+b+c;
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends