//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution {
public:

    int vr[100001];
    int vl[100001];
    int v[100001];
    map<Node*,int> ml;
     map<Node*,bool> mm;
    int t;
    int ans;
    int y;
    
   pair<int,int> d2(Node* r){
        pair<int,int> pp={-2,-2};
        pair<int,int> p={-1,-1};
        
        
        if(r==NULL){return p;}
        pair<int,int> s1  = d2(r->left);
        pair<int,int> s2 =  d2(r->right);
            mm[r]=false;
        int ii = r->data;
        int a1 ,a2,a3,a4;
        if(s1==pp || s2==pp){
    
          mm[r]=false;
        return pp;
        }
        if(s1==p &&s2==p){
            p.first=ii;
        p.second=ii;
          mm[r]=true;
        return p;
        }
        a1=ii,a4=ii;
        if(s1!=p){
            a1=s1.first;
            a2=s1.second;
            if(a2>=ii){return pp;}
            
        }
        if(s2!=p){
            a3=s2.first;
            a4=s2.second;
            if(a3<=ii){return pp;}
            
        }
        
        p.first=a1;
        p.second=a4;
        // cout<<r->data<<" ";
        mm[r]=true;
        return p;
    }
    
    
    
    
    
    
    
    
    int dd(Node* r){
        if(r==NULL){return 0;}
        int a1=0;
        int a2 = dd(r->left)+dd(r->right)+r->data;
        ml[r]=a2;
       
        return a2;
    }
    
    int d1(Node * r){
        if(r==0){return 0;}
        int a1= 1+d1(r->left)+d1(r->right);
        if(ml[r]==t && mm[r]){
            y=1;
            // cout<<r->data<<" ";
            ans = min(ans,a1);
        }
        return a1;
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        ans = INT_MAX;
        t = target;
        y=0;
        dd(root);
        d2(root);
        d1(root);
        // cout<<y<<" ";
       if(y==0){return -1;}
       
         return ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends