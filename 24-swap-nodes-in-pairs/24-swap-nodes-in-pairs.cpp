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
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;
        ListNode* nex = dummy;
        ListNode* pre = dummy;

        int count = 0;
        while(curr->next!=NULL){
            curr = curr->next;
            count++;
        }

        while(count>=2){
            curr=  pre->next;
            nex = curr->next;
            for(int i=1;i<2;i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            count-=2;
        }
        return dummy->next;
    }
};