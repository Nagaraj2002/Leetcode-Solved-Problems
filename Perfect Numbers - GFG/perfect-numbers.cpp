//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N==1){
            return 0;
        }
        long long int sum=0;
        for(long long int i=2;i*i<=N;i++){
            if(N%i==0){
                if(i==N/i){
                      sum+=i;
                }else{
                  sum+=i;
                  sum+=(N/i);
                }
            }
        }
        sum+=1;
     return (sum==N);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends