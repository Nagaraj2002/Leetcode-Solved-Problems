//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int grid[N][N], int i, int j, int n){
        for(int k = 0; k < 9; k++){
            if(grid[k][j] == n || grid[i][k] == n) return false;
        }
        int sr = i/3*3, sc = j/3*3;
        for(int k = sr; k < sr+3; k++)
            for(int l = sc; l < sc+3; l++)
                if(grid[k][l] == n) return false;
        return true;
    }
    
    bool fun(int grid[N][N], int row, int col){
        if(row == 9) return true;
        int nrow = 0, ncol = 0;
        if(col != 8){
            nrow = row;
            ncol = col+1;
        } else {
            nrow = row+1;
            ncol = 0;
        }
        
        if(grid[row][col] != 0){
            if(fun(grid, nrow, ncol)) return true;
        }
        else {
            for(int n = 1; n < 10; n++){
                if(isSafe(grid, row, col, n)){
                    grid[row][col] = n;
                    if(fun(grid, nrow, ncol)) return true;
                    else grid[row][col] = 0;
                }
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  {
        // Solving By Backtracking Approach
        // for(int i = 0; i < N; i++)
        //     for(int j = 0; j < N; j++)
        //         if(grid[i][j] == 0){
        //             for(int n = 1; n < 10; n++){
        //                 if(isSafe(grid, i, j, n)){
        //                     grid[i][j] = n;
        //                     if(SolveSudoku(grid)) return true;
        //                     else grid[i][j] = 0;
        //                 }
        //             }
        //             return false;
        //         }
                
        return fun(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends