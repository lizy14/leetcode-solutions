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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = nullptr;
        ListNode *q = p, *head;
        int overflow = 0;
        while(1){
            bool initial=(p==nullptr);
            p = new ListNode(0);
            if(initial) head = p;
            int v1=0, v2=0;
            if(l1) v1=l1->val;
            if(l2) v2=l2->val;
            if(!l1 && !l2 && !overflow) return head;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            int sum = v1+v2+overflow;
            p->val = (sum)%10;
            if((sum)>=10)
                overflow = 1;
            else
                overflow = 0;
            if(q)
                q->next = p;
            q=p;
        }
    }
};/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = nullptr;
        ListNode *q = p, *head;
        int overflow = 0;
        while(1){
            bool initial=(p==nullptr);
            p = new ListNode(0);
            if(initial) head = p;
            int v1=0, v2=0;
            if(l1) v1=l1->val;
            if(l2) v2=l2->val;
            if(!l1 && !l2 && !overflow) return head;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            int sum = v1+v2+overflow;
            p->val = (sum)%10;
            if((sum)>=10)
                overflow = 1;
            else
                overflow = 0;
            if(q)
                q->next = p;
            q=p;
        }
    }
};
