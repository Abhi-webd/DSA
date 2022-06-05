/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode *p, *q;
        p = q = head;
        do{
            p = p->next;
            q = q->next;
            q = q !=  NULL ? q->next : NULL;
        }while(p && q && p != q);
        
        if( p == q && p != NULL){
            return true;
        }
        return false;
    }
};
