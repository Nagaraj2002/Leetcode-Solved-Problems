//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &v) {
        // k= group size
        
        if(n%k>0){
            return false;
        }
        map<int,int> mp;
        for(auto it:v){
            mp[it]++;
        }
        // put all the size() with its frquency in the (min)p_queue
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        int cnt=0;
        int last=-1;
        queue<pair<int,int>> q;
        while(pq.size()>0){
            int t=pq.top().first;
            int val=pq.top().second;
            pq.pop();
            // take top ele of the heap and check if the last element and 
            // the top element are coincidnt if not return false
            // if yes then put the last ele to curr op element and move forward
            if(val-1>0){
                q.push({t,val-1});
            }
            // unit the group size is not reach dont re push the value of heap by subtracting one from it 
            // to pq again till then put the value in queue
            cnt++;
            if(last>=0){
                if(t-last!=1){
                    return false;
                }else{
                    last=t;
                }
            }
            last=t;
            if(cnt==k){
                while(q.size()>0){
                    pq.push(q.front());
                    q.pop();
                }
                last=-1;
                cnt=0;
            }
        }
        // if int the end it finds that the value of cnt is not 0 means still some element left int group 
        if(cnt>0){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends