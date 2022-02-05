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
class cmp{
    public:
    bool operator()(ListNode* l1, ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        
        ListNode* temp = new ListNode(100);
        ListNode* res = temp;
        while(!pq.empty()){
            ListNode* node = pq.top(); 
            temp->next = node;
            temp = node;
            pq.pop();
            if(node->next)pq.push(node->next);
        }
        return res->next;
    }
};