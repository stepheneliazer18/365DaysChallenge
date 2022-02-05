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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode* res;

        if(l1->val < l2->val){
            res = l1;
            res->next = mergeTwoLists(l1->next,l2);
        }
        else{
            res = l2;
            res->next = mergeTwoLists(l1,l2->next);
        }
        return res;
    }
    void mergeSort(ListNode* &head){
        if(!head || !head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newhead = slow->next;        
        slow->next = NULL;
        
        mergeSort(head);
        mergeSort(newhead);
        
        head = mergeTwoLists(head,newhead);
        
    }
    ListNode* sortList(ListNode* head) {
        mergeSort(head);
        return head;
    }
};