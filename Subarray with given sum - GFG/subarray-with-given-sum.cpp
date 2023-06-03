//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum=0;
        int j=0;
        vector<int> a;
        a.push_back(-1);
        for(int i=0; i<=n; i++)
        {
            for(j; sum>s; j++)
            {
                sum=sum-arr[j];
            }
        
            if(sum==s && s!=0) 
            {
                a.pop_back();
                a.push_back(j+1);
                a.push_back(i);
                break;
            }
            
            if(sum<s) sum+=arr[i];
        }
        
        return a;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends