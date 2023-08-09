//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public: 
    long long int largestPrimeFactor(int aabbccddeeffgghhiijjkkllmmnnoo) {
        int zz = 1 ; 
        for(int xx = 2; xx <= aabbccddeeffgghhiijjkkllmmnnoo; xx++) {
            while(aabbccddeeffgghhiijjkkllmmnnoo % xx == 0) {
                zz = max(zz, xx);
                aabbccddeeffgghhiijjkkllmmnnoo /= xx;
            }
        }
       if(zz == 1) return aabbccddeeffgghhiijjkkllmmnnoo;
       else return zz;
    }

};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends