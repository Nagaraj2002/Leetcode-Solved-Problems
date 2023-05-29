//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dict, string pat) {
          vector<string>res;
          bool flag=0;
          for(int i=0;i<Dict.size();i++){
              int j=0;
              string str=Dict[i];
              string ans="";
              while(j<str.size()){
                  if(str[j] - 'A'< 26){
                      ans+=str[j];
                  }
                  if(ans == pat){
                      flag=1;
                      res.push_back(Dict[i]);
                      break;
                  }
                  j++;
              }
          }
          
          if(flag==0)res.push_back("-1");
          return res;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends