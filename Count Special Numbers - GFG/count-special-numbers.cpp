//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
          int count=0;
        vector<int>vis(N+1,0);
        sort(arr.begin(),arr.end());
        for(int i=0;i<N;i++)
        {
            if(vis[i]==0)
            {
                if(i+1<N && arr[i]==arr[i+1])
                count++;
                
                for(int j=i+1;j<N;j++)
                {
                    if(arr[j]%arr[i]==0)
                    {
                        if(vis[j]==0)
                        {
                            vis[j]=1;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends