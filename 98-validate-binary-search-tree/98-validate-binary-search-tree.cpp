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
    vector<int> vec;
    
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        
        vector<int> temp = vec;
        sort(temp.begin(),temp.end());
        set<int> st;
        for(auto &it: temp) st.insert(it);
        if(st.size() != temp.size()) return false;
        return vec == temp;
    }
};