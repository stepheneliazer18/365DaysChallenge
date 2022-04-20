class BSTIterator {
private:
    stack<int> s;
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->right);
            s.push(root->val);
            inorder(root->left);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int res = s.top();
        s.pop();
        return res;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};