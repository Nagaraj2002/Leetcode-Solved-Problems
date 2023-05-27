//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends



/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node *reverseNode(Node *head) {
        Node *curr = head, *prev = NULL;
        while(curr != NULL) {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return head;
    }
    
    struct Node* modifyTheList(struct Node *head)
    {
                // find the mid node
        Node *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // divide the list in two halves
        Node *secondHalfHead = slow->next;
        slow->next = NULL;
        
        // reverse the second half
        Node *revList = reverseNode(secondHalfHead);
        Node *temp1 = head, *temp2 = revList;
        
        while(temp1 && temp2) {
            int original = temp1->data;
            // apply rule 1
            temp1->data = temp2->data - temp1->data;
            // copy original to second half
            temp2->data = original;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        // reverse the second list again and attach it to the original list
        Node *finalReversed = reverseNode(revList);
        
        slow->next = finalReversed;
        
        return head;

    }
};





//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends