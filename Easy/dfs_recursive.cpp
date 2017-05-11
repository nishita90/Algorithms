/*
DFS: Recursive traversal of binary tree

** Recursion basically puts returned values on stack.
** Use this to remember this algorithm.
*/

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 class Solution{
 public:
   void dfs_traversal(TreeNode* root){
     if (root == NULL)
      return NULL;
      if(root->left != NULL) dfs_traversal(root->left);
      if(root->right != NULL) def_traversal(root->right);
      std::cout<<" "<<root->val;

   }
 }
