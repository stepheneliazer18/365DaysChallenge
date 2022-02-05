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

        vector<ListNode*> vec;
        for(auto &it: lists){
            vec.push_back(it);
        }
        
        ListNode* res = new ListNode(1000);
        ListNode* temp = res;
        
        while(1){
            int min_val = INT_MAX;
            int ind = INT_MAX;
            bool flag = true;
            for(int i=0;i<vec.size();i++){
                if(vec[i]!=NULL && vec[i]->val < min_val){
                    min_val = vec[i]->val;
                    ind = i;
                    flag = false;
                }
            }
            if(flag) break;
            
            res->next = new ListNode(min_val);
            vec[ind] = vec[ind]->next;
            res = res->next;
        }
        return temp->next;
    }
};