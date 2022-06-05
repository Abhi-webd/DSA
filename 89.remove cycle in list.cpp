 Node *slow,*fast;
       slow = head;
       fast = head;
       while(fast!=NULL && fast->next!=NULL)
       {
           slow = slow->next;
           fast = fast->next->next;
           if(slow==fast)
           {
               break;
           }
       }
       if(slow==fast && fast!=head)
       {
           RemoveLoop(head,slow);
       }
       else if(slow==fast && fast==head)
       {
           RemoveHeadLoop(head,slow);
       }
   }
   void RemoveHeadLoop(Node *head, Node *slow)
   {
       while(slow->next!=head)
       {
           slow = slow->next;
       }
       slow->next = NULL;
   }
   void RemoveLoop(Node *head, Node *slow)
   {
       Node *sta=head,*pre;
       while(sta!=slow)
       {
           pre = slow;
           slow = slow->next;
           sta = sta->next;
       }
       pre->next = NULL;
   }
};
