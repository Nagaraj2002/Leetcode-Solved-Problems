//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution{
public:
    static bool cmp(long long a, long b){
        return a>b;
    }
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long> ans;
        vector<int> help  = arr;
        sort(help.begin(),help.end());
        long long sum = help[0];
        ans.push_back(0);
        unordered_map<long,long>mm;
        mm[help[0]]++;
        for(int i = 1 ; i < n ; i++){
            if(mm.find(help[i])!=mm.end()){
                ans.push_back(sum - (help[i])*mm[help[i]]);
                
            }
            else ans.push_back(sum);
            sum+=help[i];
            mm[help[i]]++;
        }
        unordered_map<long long,long long>mp;
        for(int i = 0 ; i < n ; i++){
            mm[help[i]] = ans[i];
        }
        for(int i = 0 ; i < n ; i++){
            ans[i] = mm[arr[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends