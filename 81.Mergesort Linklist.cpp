node* mergerec(node* head1, node* head2){
       if(head1 == NULL){
           return head2;
       }
       if(head2 == NULL){
           return head1;
       }

       node* c ;
       if(head1->data < head2->data){
           c = head1;
           c->next = mergerec(head1->next,head2);
       }
       else{
           c= head2;
           c->next = mergerec(head1,head2->next);
       }
       return c;
   }

   node* midPoint(node * head){
       node* slow = head;
       node* fast= head->next;

       while(fast != NULL && fast->next != NULL){
           slow = slow->next;
           fast = fast->next->next;
       }

       return slow;
   }

   node* mergeSort(node*  head){
       if(head == NULL || head->next == NULL){
           return head;
       }

       node* mid = midPoint(head);
       node* a = head;
       node* b = mid->next;
       mid->next = NULL;
       a = mergeSort(a);
       b = mergeSort(b);
       return mergerec(a,b); 
   }
