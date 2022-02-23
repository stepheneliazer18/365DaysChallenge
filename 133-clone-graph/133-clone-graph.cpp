/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* cur, Node* node, vector<Node*>& vis){
        vis[node->val] = node;
        for(auto &it: cur->neighbors){
            if(!vis[it->val]){
                Node* newnode = new Node(it->val);
                (node->neighbors).push_back(newnode);
                dfs(it, newnode, vis);
            }
            else (node->neighbors).push_back(vis[it->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        vector<Node*> vis(1000,NULL);
        
        Node* res = new Node(node->val);
        vis[node->val] = res;
        
        for(auto &it: node->neighbors){
            if(!vis[it->val]){
                Node* newnode = new Node(it->val);
                (res->neighbors).push_back(newnode);
                dfs(it, newnode, vis);
            }
            else (res->neighbors).push_back(vis[it->val]);
        }
        
        return res;
    }
};