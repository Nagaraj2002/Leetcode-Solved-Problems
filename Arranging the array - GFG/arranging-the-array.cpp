//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends


class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            queue<int>q1;
            queue<int>q2;
            
            for(int i=0;i<n;i++){
                
                if(arr[i]<0){
                    q1.push(arr[i]);
                }
                else{
                    q2.push(arr[i]);
                }
            }
            
            for(int i=0;i<n;i++){
                
                if(!q1.empty()){
                    arr[i]=q1.front();
                    q1.pop();
                }
                else{
                    arr[i]=q2.front();
                    q2.pop();
                }
            }
            
            
        }
};



//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends