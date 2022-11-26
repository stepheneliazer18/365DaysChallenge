/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int getValue(int& i, string data){
        string temp = "";
        while(data[i] != ',') temp += data[i++];
        i++;
        return stoi(temp);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string ans;
        
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + ',';
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                ans += to_string(node->left->val) + ',';
            }
            else ans += "#,";
            if(node->right){
                q.push(node->right);
                ans += to_string(node->right->val) + ',';
            } 
            else ans += "#,";
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#') return NULL;
        
        int i = 0;
        TreeNode* root = new TreeNode(getValue(i,data));
        
        queue<TreeNode*> q;
        q.push(root);        
             
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
                                    
            if(data[i] == '#'){
                node->left = NULL;
                i += 2;
            }
            else{
                TreeNode* newNode = new TreeNode(getValue(i,data));
                node->left = newNode;
                q.push(newNode);
            }
            
            if(data[i] == '#'){
                node->right = NULL;
                i += 2;
            }
            else{
                TreeNode* newNode = new TreeNode(getValue(i,data));
                node->right = newNode;
                q.push(newNode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));