class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev, *cur;
        
        //deal with leading 'val's
        while(head != NULL && head->val == val) head = head->next;
        
        //deal with 'val's not in head of list
        cur = head;
        while(cur != NULL){
            if(cur->val == val){
                prev->next = cur->next;
                /**
                [1,2,2,1]: prev:1,cur:2
                [1,2,1]: prev:1,cur:2
                [1,1]: prev:1,cur:1
                **/
            }else{
                //move prev when the next node of prev is not 'val'
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};