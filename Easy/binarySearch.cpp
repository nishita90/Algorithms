/*
Given a binary search tree and a value, return 1 if the value exists and 0 if it doesn't.
** Note: remember left->val < root->val < right->val !
For balanced binary tree, avg complexity of search is O(logn)
If unbalanced, worse case complexity is O(n)
*/

// Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
 public:
     int b_search(TreeNode* root, int value) {
       if(root == NULL)
        return 0;
       TreeNode* current_node = root;

       while(current_node != NULL){
         if(root->val == value)
          return 1;
        else if(root->val < value)
          current_node = root->right;
        else //if(root->val > value)
          current_node = root->left;
       }
       return 0;
     }

     int b_search_recursive(TreeNode* node, int val){
       if(root == NULL)
        return 0;
        if(root->val == value)
          return 1;
        else if(root->val < value)
          return b_search_recursive(root->right, value);
        else
          return b_search_recursive(root->left, value);
     }

}
