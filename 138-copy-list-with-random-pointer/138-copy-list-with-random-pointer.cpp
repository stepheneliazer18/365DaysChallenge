/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* getNewNode(Node* temp, unordered_map<Node*, Node*>& mp){
        if(!temp) return NULL;
        if(mp.find(temp) == mp.end())  mp[temp] = new Node(temp->val);
        return mp[temp];
    }
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
            Node* nwNode = getNewNode(temp, mp);
            nwNode->next = getNewNode(temp->next, mp);
            nwNode->random = getNewNode(temp->random, mp);
            temp = temp->next;
        }
        
        return mp[head];
    }
};