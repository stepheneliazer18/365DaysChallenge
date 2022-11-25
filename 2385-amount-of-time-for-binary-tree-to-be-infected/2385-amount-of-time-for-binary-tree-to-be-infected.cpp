/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        
        map<TreeNode*, TreeNode*> parentTracker;
        parentTracker[root] = root;
        
        TreeNode* target;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->val == start){
                target = node;
            }
            
            if(node->left) {
                q.push(node->left);
                parentTracker[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parentTracker[node->right] = node;
            }
        }
        
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;
        
        int seconds = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(!visited[parentTracker[node]]){
                    q.push(parentTracker[node]);
                    visited[parentTracker[node]] = true;
                }
            }
            seconds++;
        }
        
        return seconds - 1;
    }
};