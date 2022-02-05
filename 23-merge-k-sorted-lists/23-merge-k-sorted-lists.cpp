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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

        ListNode* res = lists[0];
        for(int i=1;i<lists.size();i++){
            res = mergeTwoLists(res,lists[i]);
        }
        
        return res;
    }
};

/*
[[]]
[[],[]]
[]
*/