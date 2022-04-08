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
    ListNode* reverse(ListNode* &head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;  
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        
        while(temp){
            temp->next = reverse(temp->next);
            temp = temp->next;
        }
    }
};