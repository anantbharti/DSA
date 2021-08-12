#include <bits/stdc++.h>
using namespace std;

/*node for tree*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef TreeNode tn;

/* insert an element */
void insert(tn* &root, int data)
{
	tn* temp=new tn(data);
	if(root==NULL)
		root=temp;
    else if(data>root->val)
        insert(root->right,data);
    else if(data<root->val)
        insert(root->left,data);
    else 
        return;
}

/* recursive tree traversal */
void traverse(tn* root)
{
    if(root==NULL)
    return;
    cout<<root->val<<" ";   //pre order
    traverse(root->left);
    cout<<root->val<<" ";   //in order
    traverse(root->right);
    cout<<root->val<<" ";   //post order
}

/* Iterative pre order traversal */
//method #1
void preOrder(Node* root)
{
    Node* cur=root;
    stack<Node*> s;
    s.push(cur);
    while(!s.empty())
    {
        cur=s.top();
        s.pop();
        cout<<cur->val<<" ";   //code here as required
        if(cur->right)
        s.push(cur->right);
        if(cur->left)
        s.push(cur->left);
    }
}
//method #2
void preOrder(Node* root)
{
    Node* cur=root;
    stack<Node*> s;
    vector<int> ans;
    while(!s.empty()||cur)
    {
        while(cur)
        {
            cout<<cur->val<<" ";   //code here as required
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        cur=cur->right;
    }
}

/* Iterative in order traversal */
void inOrder(Node* root)
{
	Node* cur=root;
	stack<Node*> s;
	while(!s.empty()||cur)
	{
	    while(cur)
	    {
		s.push(cur);
		cur=cur->left;
	    }
	    cur=s.top();
	    s.pop();
	    cout<<cur->val<<" ";  //code here as required
	    cur=cur->right;
	}
}

/* Iterative post order traversal */
void postOrder(Node* node) 
{
    Node* cur=node;
    stack<Node*> s,stk;
    s.push(cur);
    while(!s.empty())
    {
        Node* n1=s.top();
        s.pop();
        stk.push(n1);
        
        if(n1->left)
        s.push(n1->left);
        if(n1->right)
        s.push(n1->right);
    }
    while(!stk.empty())
    {
        cout<<s.top()<<" ";   //code here as required
        stk.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif

    tn* tree=NULL;
    insert(tree,4);
    insert(tree,9);
    insert(tree,3);
    insert(tree,5);
    insert(tree,6);

    print(tree);
    return 0;        
} 
