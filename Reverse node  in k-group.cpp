/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1){
            return head;
        }

        // constant storage
        ListNode *temp=head;
        // pointers for reversal
        ListNode *prv=NULL;
        ListNode *curr=head;
        ListNode *nxt=head;
        int first=0;
        int flag=1;
        int count=0;

        // count total nodes
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        curr=head;
        while(count>=k){
            for(int i=0;i<k;i++){
                ListNode *nxt=curr->next;
                curr->next=prv;
                prv=curr;
                curr=nxt;
            }
            if(first==0){
                head=prv;
                first=1;
                temp->next=curr;
            }else{
                ListNode *nxt=temp->next;
                temp->next->next=curr;
                temp->next=prv;
                temp=nxt;
            }
            prv=NULL;
            count-=k;
        }
        // head will be the first kth value in the list
        return head;
    }
};
