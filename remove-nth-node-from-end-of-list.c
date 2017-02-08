/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 

int listLength(struct ListNode* head){
    int length = 0;
        
    struct ListNode* p = head;
    while(p != NULL){
        length ++;
        p = p->next;
    }
    
    return length;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = listLength(head);
    
    int index = length - n;
    
    if(index == 0){
        return head->next;
    }
    
    struct ListNode* q;
    struct ListNode* p;
    p = head;
    while(index){
        index --;
        q = p;
        p = p->next;
    }
    q->next = p? p->next: p;
    return head;
    
}
