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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!(head->next)) return head;
        ListNode *n2 = head->next, *n1 = head, *p = n2->next;
        head = n2;
        n2->next = n1;
        n1->next = p;
        p = n1;
        while(p){
            // p->n1->n2->n3
            // p->n2->n1->n3
            auto *n1 = p->next;
            if(!n1) break;
            auto *n2 = n1->next;
            if(!n2){
                p->next = n1;
                break;
            }
            ListNode *n3 = n2->next;
            p->next = n2;
            n2->next = n1;
            n1->next = n3;
            p = n1;
        }
        return head;
    }
};
