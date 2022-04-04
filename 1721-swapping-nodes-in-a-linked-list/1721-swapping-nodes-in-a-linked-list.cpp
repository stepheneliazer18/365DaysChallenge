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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 1;
        
        ListNode* temp = head;
        ListNode* first;
        while(temp){
            if(n == k) first = temp;
            temp = temp->next;
            n++;
        }
        
        ListNode* fast = first;
        ListNode* second = head;
        while(fast->next){
            second = second->next;
            fast = fast->next;
        }
        swap(first->val,second->val);
        return head;
    }
};