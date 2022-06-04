node* mergeSorted(node* head1 ,node* head2){
       if(head1 == NULL){
           return head2;
       }
       if(head2 == NULL){
           return head1;
       }
       node* temp;
       node* t1 = head1;
       node* t2 = head2;
       node* h;

       if(head1->data < head2->data){
           h = head1;
           temp = head1;
           t1 = t1->next;
       }
       else{
           h =  head2;
           temp = head2;
           t2 = t2->next;
       }

       while(t1 != NULL && t2 != NULL){
           if(t1->data < t2->data){
               temp->next = t1;
               temp = temp->next;
               t1 = t1->next;
           }
           else{
               temp->next = t2;
               temp = temp->next;
               t2 = t2->next;
           }
       }
       while(t1 != NULL){
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
       }
       while(t2 != NULL){
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
       }
       return h;
   }

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
