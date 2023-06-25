//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends


class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        // unordered_map<vector<int> , int> mp ;
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            vector<int> arr;
            for(int j=0;j<col;j++){
                arr.push_back(M[i][j]);
            }
            if(st.find(arr)==st.end()){
               ans.push_back(arr);
            }
            st.insert(arr);
        }
        
        // vector<vector<int>> ans(mp.size());
        
        // for(auto it: mp){
        //     ans[it.second].push_back(it.first);
        // }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends