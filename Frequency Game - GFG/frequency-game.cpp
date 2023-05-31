//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        priority_queue<int> pq;
        for(int i = 0; i < n ; i++){
            pq.push(arr[i]);
        }
        int ans = 0,minFreq = INT_MAX;
        while(!pq.empty()){
            int val = pq.top(),freq = 1;
            pq.pop();
            while(!pq.empty() && pq.top() == val){
                pq.pop() , freq++;
            }
            if(freq < minFreq)
                minFreq = freq, ans = val;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends