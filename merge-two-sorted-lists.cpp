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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *p = nullptr;
        ListNode *q = nullptr;
        while(1){
            if(!l1 && !l2) break;
            if(!l1){
                q = l2;
                l2 = l2->next;
            }else if(!l2){
                q = l1;
                l1 = l1->next;
            }else if(l1->val >= l2->val){
                q = l2;
                l2 = l2->next;
            }else{
                q = l1;
                l1 = l1->next;
            }
            //update
            if(!head){
                head = q;
                p = q;
            }else{
                p->next = q;
                p = q;
            }
        }
        return head;
    }
};
