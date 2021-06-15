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

/*print element of bst in sorted order (dfs) */
void print(tn* root)
{
    if(root==NULL)
    return;
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
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
