   #include <bits/stdc++.h>
   using namespace std;

   class node{
       public:
       int data;
       node* next;

       node(int data){
           this->data = data;
           next = NULL;
       }
   };

   void insertHead(node* &head , int val){
       if(head == NULL){
           head = new node(val);
           return;
       }
       node* temp =  new node(val);
       temp->next = head;
       head = temp;
   }

   void insertmiddle(node* &head, int val , int pos){
       if(head == NULL || pos == 1){
           insertHead(head,val);
       }

       node* temp = head;
       pos = pos-1;
       while(pos){
           temp = temp->next;
           pos--;
       }
       node* t = new node(val);
       t->next = temp->next;
       temp->next = t;
   }

   node* recursiveReverse(node* head){
       if(head == NULL || head->next == NULL){
           return head;
       }

       node* shead  = recursiveReverse(head->next);
       head->next->next = head;
       head->next = NULL;
       return shead;
   }

   void print(node* head){
       node* temp = head;
       while(temp != NULL){
           cout<<temp->data<<" ";
           temp = temp->next;
       }

   }

   int main()
   {
       node* head = NULL;
       insertHead(head,10);
       insertHead(head,20);
       insertHead(head,30);
       insertHead(head,40);
       insertHead(head,50);
       insertmiddle(head,25,2);
       print(head);
       head = recursiveReverse(head);
       print(head);
       return 0;
   }
