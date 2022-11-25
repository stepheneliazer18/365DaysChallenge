/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        map<TreeNode*, TreeNode*> mp;
        mp[root] = root;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                mp[node->left] = node; 
            }
            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }
        }
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q1;
        q1.push({target,0});
        
        map<TreeNode*, int> vis;
        vis[target] = 1;
        
        while(!q1.empty()){
            auto it = q1.front();
            q1.pop();
            
            TreeNode* node = it.first;
            int level = it.second;
            
            if(level == k){
                ans.push_back(node->val);
                continue;
            }
            
            if(node->left && !vis[node->left]){
                q1.push({node->left, level+1});
                vis[node->left] = 1;
            }
            if(node->right && !vis[node->right]){
                q1.push({node->right, level + 1});
                vis[node->right] = 1;
            }
            if(!vis[mp[node]]){
                vis[mp[node]] = 1;
                q1.push({mp[node], level + 1});
            }
        }  
        
        return ans;        
    }
};