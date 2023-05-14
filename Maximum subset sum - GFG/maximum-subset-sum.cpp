//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        int dp[N]; // dp[i] = maximum sum for [0, i] elements if i-th element is included in the subset.
    dp[0] = A[0], dp[1] = A[1] + max(A[0], 0);
    for(int i = 2; i < N; i++) {
        // Either we include (i-1)-th element
       // If not, we are "forced" to include (i-2)-th element
        dp[i] = A[i] + max(dp[i-1], dp[i-2]);
    }
    return max(dp[N-1], dp[N-2]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends