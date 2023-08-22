//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxi=0;
       
        for (int i=0;i<n;i++){
            int sum1=0;
            int sum2=0;
            for (int j=0;j<n;j++){
                sum1+=matrix[i][j];
                sum2+=matrix[j][i];
            }
            maxi=max(maxi,sum1);
            maxi=max(maxi,sum2);
        }


        int ans1=0,ans2=0;
          for (int i=0;i<n;i++){
            int sum1=0;
            int sum2=0;
            for (int j=0;j<n;j++){
                sum1+=matrix[i][j];
                sum2+=matrix[j][i];
            }
           ans1+=(maxi-sum1);
           ans2+=(maxi-sum2);
        }
        return max(ans1,ans2);
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends