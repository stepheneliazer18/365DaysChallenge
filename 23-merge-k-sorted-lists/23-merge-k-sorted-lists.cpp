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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        vector<int> vec;
        for(auto &it: lists){
            ListNode* temp = it;
            while(temp){
                vec.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        sort(vec.begin(),vec.end());
        
        ListNode* temp = new ListNode(100);
        ListNode* node = temp;
        for(int i=0;i<vec.size();i++){
            temp->next = new ListNode(vec[i]);
            temp = temp->next;
        }

        return node->next;
    }
};