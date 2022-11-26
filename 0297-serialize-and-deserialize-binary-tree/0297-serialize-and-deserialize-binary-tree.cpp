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
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(!node) ans += "N,";
            else ans += to_string(node->val) + ',';
            
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string temp;
        getline(s, temp, ',');
        TreeNode* root = new TreeNode(stoi(temp));
        
        queue<TreeNode*> q;
        q.push(root);        
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
                    
            getline(s, temp, ',');
            if(temp == "N") node->left = NULL;
            else{
                TreeNode* newNode = new TreeNode(stoi(temp));
                node->left = newNode;
                q.push(newNode);
            }
            
            getline(s, temp, ',');
            if(temp == "N") node->right = NULL;
            else{
                TreeNode* newNode = new TreeNode(stoi(temp));
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