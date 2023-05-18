//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        queue<pair<int, int> > q;
        int ans=0;
        for(int i=0;i<N;i++){
            if(matrix[i][0]==1){
                q.push({i,0});
                matrix[i][0]=-1;
            }
            if(matrix[i][M-1]==1){
                q.push({i,M-1});
                matrix[i][M-1]=-1;
            }
        }
        for(int j=0;j<M;j++){
            if(matrix[0][j]==1){
                q.push({0,j});
                matrix[0][j]=-1;
            }
            if(matrix[N-1][j]==1){
                q.push({N-1,j});
                matrix[N-1][j]=-1;
            }
        }
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1>=0 && y1>=0 && x1<N && y1<M && matrix[x1][y1]==1){
                    matrix[x1][y1]=-1;
                    q.push({x1,y1});
                }
            }
        }
        for(int i=1;i<(N-1);i++){
            for(int j=1;j<(M-1);j++){
                if(matrix[i][j]==1){
                    queue<pair<int, int> > qq;
                    qq.push({i,j});
                    ans++;
                    while(!qq.empty()){
                        int x=qq.front().first;
                        int y=qq.front().second;
                        qq.pop();
                        for(int i=0;i<4;i++){
                            int x1=x+dx[i];
                            int y1=y+dy[i];
                            if(x1>=0 && y1>=0 && x1<N && y1<M && matrix[x1][y1]==1){
                                matrix[x1][y1]=-1;
                                qq.push({x1,y1});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends