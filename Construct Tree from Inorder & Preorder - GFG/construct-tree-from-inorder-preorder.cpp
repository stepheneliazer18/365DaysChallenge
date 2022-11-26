//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
private:
    Node* buildTreeHelp(int preorder[], int inorder[], map<int,int>& inMap, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd) return NULL;
        
        Node* root = new Node(preorder[preStart]);
        int rootIndex = inMap[root->data];
        
        int leftInStart = inStart;
        int leftInEnd = rootIndex - 1;
        int rightInStart = rootIndex + 1;
        int rightInEnd = inEnd;
        
        int leftInSize = leftInEnd - leftInStart + 1;
        
        int leftPreStart = preStart + 1;
        int leftPreEnd = preStart + leftInSize;
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = preEnd;
        
        root->left = buildTreeHelp(preorder, inorder, inMap, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
        root->right = buildTreeHelp(preorder, inorder, inMap, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
        
        return root;
    }
public:
    Node* buildTree(int inorder[], int preorder[], int n){
        if(n == 0) return NULL;
        
        map<int,int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }
        
        return buildTreeHelp(preorder, inorder, inMap, 0, n-1, 0, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends