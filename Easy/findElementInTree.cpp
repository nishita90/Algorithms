/*
Traverse tree - If binary search tree - you can limit traversal based on curr_node val2
else, traverse entire tree
*/

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
  bool findElem(TreeNode* root, int val){
    if (root == NULL){
      return false;
    }
    int curr_val = root->val;
    if (curr_val == val){
      return true;
    }
    // If binary search Tree
    /* We check conditionally;
    if (val < curr_val)
      if(findElem(root->left, val))
        return true;
    else
      if(findElem(root->right, val))
        return true;
    */
    else{
      if(findElem(root->left, val)){
        return true;
      }
      else{
        if(findElem(root->right, val)){
          return true;
        }
      }
    }

    return false;
  }
};
