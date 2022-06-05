// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 

 // } Driver Code Ends
/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

class Solution
{
    public:
    Node *zigZag(Node* head)
    {
     // your code goes here
     if(head == NULL ||  head->next == NULL){
         return head;
     }
     
     if(head->data > head->next->data){
         int temp = head->data;
         head->data = head->next->data;
         head->next->data = temp;
     }
     
     Node* t1 = head->next;
     Node* t2 = head->next->next;
     int count = 1;
     while(t2){
         if(count%2 != 0){
             if(t1->data < t2->data){
                 int temp = t1->data;
                 t1->data = t2->data;
                 t2->data = temp;
             }
             count++;
         }
         else{
             if(t1->data > t2->data){
                 int temp = t1->data;
                 t1->data = t2->data;
                 t2->data = temp;
             }
             count++;
         }
         t1 = t1->next;
         t2 = t2->next;
     }
     return head;
    }
};

// { Driver Code Starts.


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
