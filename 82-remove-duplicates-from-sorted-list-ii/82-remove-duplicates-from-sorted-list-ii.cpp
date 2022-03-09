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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        ListNode* i = head;
        ListNode* j = head;
        
        while(i && j){
            if(i->next && i->next->val == i->val){
                j = i;
                if(!j->next) res->next = i;
                else{
                    while(j->val == j->next->val){
                        j = j->next;
                        if(!j->next) break;
                    }
                }
                i = j->next;
            }
            else{
                res->next = new ListNode(i->val);
                res = res->next;
                i = i->next;
            }
        }
        return dummy->next;
    }
};