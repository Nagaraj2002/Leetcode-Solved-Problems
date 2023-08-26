//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
       vector<int> v(26,0);
       int ct=0,i=0,j=0,ans=-1,n=s.size();
       while(i<n && j<n){
           if(ct<=k){
           int p=s[i]-'a';
           if(v[p]==0){
               v[p]++;
              ct++;
           }else 
              v[p]++;
              i++;
           }
           if(ct>k){
               while(ct>k){
                   int p=s[j]-'a';
                   if(v[p]>0)
                   v[p]--;
                   if(v[p]==0){
                       ct--;
                   }
                   j++;
               }
           }
           if(ct==k){
               ans=max(ans,i-j);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends