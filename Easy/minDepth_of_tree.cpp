/*
Find the min height of a binary tree. Height of empty tree is 0
Algorithm: Recursively calculate depth of tree.
- If tree is empty, return 0
- Else
    - calculate the min depth of the left subtree recursively.
    - calculate the min depth of the right subtree recursively.
    - Add 1 to min of above 2 options, for the root node.
*/

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){};
}

class Solution{
public:
  int minDepth(TreeNode *root){
    if (root == NULL)
      return 0;
    else{
      int leftDepth = minDepth(root->left);
      int rightDepth = minDepth(root->right);

      return (1 + (std::min(leftDepth, rightDepth)));
    }
  }
}
