//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        //Your code here
         vector<string>v;
        int n=S.length();
        if(n==0) n=1;
        else if(n==3) n=6;
        else if(n==4) n=24;
        else if(n==5) n=120;
        sort(S.begin(),S.end());
        while(n--)
        {
           v.push_back(S);
           next_permutation(S.begin(),S.end());
        }
        sort(v.begin(),v.end());
        return v;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends