//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {   
        // code here.. 
        if(sizeOfStack%2==0)
        {
            int mid=sizeOfStack/2;
            int arr[mid];
            for(int i=1;i<=mid;i++)
            {
                arr[i]=s.top();
                s.pop();
            }
            s.pop();
            for(int i=mid;i>0;i--)
            {
                s.push(arr[i]);
            }
        }
        else
        {
            int mid = sizeOfStack/2 + 1;
            int arr[mid];
            for(int i=1;i<mid;i++)
            {
                arr[i]=s.top();
                s.pop();
            }
            s.pop();
            for(int i=mid-1;i>0;i--)
            {
                s.push(arr[i]);
            }
        }
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends