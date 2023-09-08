//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
  public:
  int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> dis(100000, 1e9);
         q.push({0,start});
        dis[start]=0;
       
        if(start==end) return 0;
        while(!q.empty()){
            int node= q.front().second;
            int steps= q.front().first;
            q.pop();
            
            for(auto x: arr){
                int adjNode= (x*node)%mod;
                if(steps+1 < dis[adjNode]){
                    dis[adjNode]=steps+1;
                    
                    if(adjNode==end) return steps+1;
                    q.push({steps+1 , adjNode});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends