//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
  vector<vector<long long>>multiplication(vector<vector<long long>>&first,vector<vector<long long>>&second){
      vector<vector<long long>>matrix(2,vector<long long>(2,0));
      for(int i=0;i<2;i++){
          for(int j=0;j<2;j++){
              int flag=0;
              for(int k=0;k<2;k++){
                 flag=(flag%mod+(first[i][k]*second[k][j])%mod)%mod; 
              }
          
          matrix[i][j]=flag%mod;
          }
      }
      return matrix;
  }
  
  vector<vector<long long>> matrixexponent(vector<vector<long long>>&third,long long int z){
      if(z==1){
          return third;
      }
      
      vector<vector<long long>>temporary=matrixexponent(third,z/2);
      vector<vector<long long>>finally=multiplication(temporary,temporary);
      if(z%2==1){
          finally=multiplication(finally,third);
      }
      return finally;
      
  }
    int countStrings(long long int N) {
       vector<vector<long long >>matrix(2,vector<long long>(2,0));
        matrix[0][0]=1;
        matrix[0][1]=1;
        matrix[1][0]=1;
        matrix[1][1]=0;
        matrix=matrixexponent(matrix,N);
        return (matrix[0][0]+matrix[0][1])%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends