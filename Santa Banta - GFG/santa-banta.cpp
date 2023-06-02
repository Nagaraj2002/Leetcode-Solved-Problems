//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
   vector<int>data;
    void precompute()
    {
        vector<bool>prime(1e6+1,true);
         prime[0]=false;
        prime[1]=false;
        for(int i=2;i<1e6+1;i++)
        {
            if(prime[i]==true)
            {
                data.push_back(i);
                int j=2*i;
                while(j<1e6+1)
                {
                    prime[j]=false;
                    j=j+i;
                }
            }
        }
    }
    void dfs(int src, vector<vector<int>> &g,vector<bool>&visited,int &count)
    {
       
            visited[src]=true;
            count++ ;
            for(auto ele:g[src])
            {
                if(visited[ele]==false)
                 dfs(ele,g,visited,count);
            }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        int ans=0;
        vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                int count=0;
                dfs(i,g,visited,count);
                ans=max(ans,count);
            }
        }
        
        if(ans==1)
        return -1;
        
      
        return data[ans-1]; 
    }
};



//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends