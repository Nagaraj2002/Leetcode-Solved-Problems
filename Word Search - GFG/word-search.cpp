//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    bool flag = false;
    void dfs( string word, vector<vector<char>>& board, int i, int j, int n, int m, int k, vector<vector<int>>&vis )
    {
        
        if( k == word.size())
        {
            flag = true;
            return;
        }
        if( i >= m || j >= n ||  i < 0 || j < 0  || k == word.size()  || word[k] != board[i][j]  || vis[i][j] == 1 || flag == true)
        {
            return;
        }
        // cout<<i<<" "<<j<<endl;
        // cout<<" ";
        vis[i][j]=1;
        dfs( word, board, i, j+1, n, m, k+1, vis );
        dfs( word, board, i+1, j, n, m, k+1, vis );
        dfs( word, board, i, j-1, n, m, k+1, vis );
        dfs( word, board, i-1, j, n, m, k+1, vis );
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        // Code here
        int m = board.size();
        int n = board[0].size();
        int k = 0;
        
        for(int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( word[k] == board[i][j] )
                {
                    vector<vector<int>>vis(m,vector<int>(n,0));
                   
                    dfs( word, board, i, j, n, m, k, vis );
                    if( flag )
                    {
                        return true;
                    }
                }
            }   
            // cout<<endl;
        }
        return false;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends