//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h> 
#include <vector> 
using namespace std; 

// } Driver Code Ends
class Solution
{
  public:
    vector<int> findIndex(int a[], int n, int key)
    {
        //code here.
        int temp ,count;
        temp = -1;
        count = -1;
        for(int i=0,j=n-1;i<n, j>=0;i++,j--){
            if(key==a[i]){
                temp=i;
            }
            if(key==a[j]){
                count=j;
            }
        }
        vector<int> Gaddi;
        Gaddi.push_back(count);
        Gaddi.push_back(temp);
       return Gaddi ;
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
        vector<int> res;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        res=ob.findIndex(arr, n, key);
        for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
        cout << "\n";
    }
    
    return 0;
}

// } Driver Code Ends