//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    int drow[]={-1,0,1,1,1,0,-1,-1};
	    int dcol[]={1,1,1,0,-1,-1,-1,0};
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                
	                for(int k=0;k<8;k++){
	                    int p=1;
	                    int nrow=i+drow[k];
	                    int ncol=j+dcol[k];
	                    
	                    while(p<word.size() && nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==word[p]){
	                        p++;
	                        nrow+=drow[k];
	                        ncol+=dcol[k];
	                    }
	                    if(p==word.size()){
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends