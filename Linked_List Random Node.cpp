class Solution {
public:
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* cur = head;
        while(cur){
            v.push_back(cur->val);
            cur = cur->next;
        }
    }
    int getRandom() {
        return v[rand()%v.size()];
    }
};
