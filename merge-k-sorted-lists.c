/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int id_min;
    int min;
    int b_minAssigned;
    
    struct ListNode* head = NULL;
    struct ListNode* p;
    
    while(233){
        
        // find min val among heads
        b_minAssigned = 0;
        int i;
        for (i = 0; i < listsSize; i++){
            if(lists[i] != NULL){
                int val = lists[i]->val;
                if((!b_minAssigned) || val < min){
                    min = val;
                    id_min = i;
                    b_minAssigned = 233;
                }
            }
        }
        
        
        if(!b_minAssigned){
            // all lists NULL
            break;
        }else{
            // id_min, min 
            
            struct ListNode* next = lists[id_min]->next;
            lists[id_min] = next;
            
            struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
            new_node->val = min;
            
            if(!head){
                head = new_node;
                p = head;
            }else{
                p->next = new_node;
                p = new_node;
            }
        }
    }
    
    if(p) p->next = NULL;
    return head;
}
