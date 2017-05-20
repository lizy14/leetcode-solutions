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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        
        int n = 1;
        auto p = head;
        while(p -> next != nullptr){
            p  = p -> next;
            n ++;
        }
        
        // n is length of list
        // p points to tail
        
        k %= n;
        
        p -> next = head;
        
        auto q = head;
        for(int i = 1; i <= n - k - 1; ++i){
            q = q -> next;
        }
        /*
            q 
        1 2 3 4 5
        */
        // q -> next is the new head
        
        auto new_head = q -> next;
        q -> next = nullptr;
        
        return new_head;
        
    }
};
