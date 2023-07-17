//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans = "";
		    vector<int> v(26, 0);
		    queue<char> q;
		    for(char c: A)
		    {
		        v[c-'a']++;
		        if(v[c-'a'] == 1)
		            q.push(c);
		        
		        while(!q.empty() && v[q.front()-'a'] > 1)
		            q.pop();
		        
		        if(q.empty())
		            ans += '#';
		        else
		            ans += q.front();
		    }
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends