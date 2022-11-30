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
private:
    vector<int> inOrder(TreeNode* root) {
        vector<int> inorder;
        
        TreeNode* cur = root;
        
        while(cur){
            if(!cur -> left) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right == cur){
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        
        return inorder;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        // int counter = 0;
        
//         TreeNode* cur = root;
        
//         while(cur){
//             if(!cur -> left) {
//                 if(++counter == k) return cur->val;
//                 cur = cur->right;
//             }
//             else {
//                 TreeNode* prev = cur->left;
//                 while(prev->right && prev->right != cur){
//                     prev = prev->right;
//                 }
                
//                 if(prev->right == cur){
//                     prev->right = NULL;
//                     if(++counter == k) return cur->val;
//                     cur = cur->right;
//                 }
//                 else{
//                     prev->right = cur;
//                     cur = cur->left;
//                 }
//             }
//         }
        vector<int> in = inOrder(root);
        return in[k-1];
        return -1;
    }
};