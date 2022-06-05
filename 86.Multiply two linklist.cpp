//concept of module a here highest value is used to module when the ans can be greater then highest unsigned value it will be mentioned as
//Note: The output could be large take modulo 109+7.
//it is mentioned in question to use modulo 

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long x=0;
  long long y=0;
  long long a = 1000000007;
  Node* temp = l1;
  while(temp != NULL){
      x = (x*10)%a+ temp->data;
      temp = temp->next;
  }
  Node* temp2 = l2;
  while(temp2 != NULL){
      y = (y*10)%a+temp2->data;
      temp2 = temp2->next;
  }
//   cout<<x<<" "<<y<<endl;
  return  x*y%a;
}
