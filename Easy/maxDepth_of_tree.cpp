/*
Find the Height of a binary tree. Height of empty tree is 0
Algorithm: Recursively calculate depth of tree.
- If tree is empty, return 0
- Else
    - calculate the max depth of the left subtree recursively.
    - calculate the max depth of the right subtree recursively.
    - Add 1 to max of above 2 options, for the root node.
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
  int maxDepth(TreeNode* root){
    if(root == NULL)
      return 0;
    else
    {
      // Compute the depth of each subtree
      int leftDepth  = maxDepth(root->left);
      int rightDepth = maxDepth(root->right);

      return (std::max(leftDepth, rightDepth) + 1);
    }
  }
}
