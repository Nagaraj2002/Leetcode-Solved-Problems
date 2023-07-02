//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int i=0,j=n-1;
        long long suml=a[i];
        long long sumr=a[j];
        while(i<j){
            if(suml<sumr){
                i++;
                suml+=a[i];
            }
            else if(sumr<suml){
                j--;
                sumr+=a[j];
            }else{
                if(i+1==j && a[i]==a[j]){
                    return -1;
                }
                i++;
                j--;
                suml=a[i];
                
                sumr=a[j];
            }
        }
        if(suml==sumr){
            return i+1;
        }else{
            return -1;
            
        }
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends