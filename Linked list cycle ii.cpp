class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode* cur = head;
        while(cur != NULL){
            if(visited.find(cur) != visited.end()){
                return cur;
            }else{
                visited.insert(cur);
            }
            cur = cur->next;
        }
        return NULL;
    }
};
