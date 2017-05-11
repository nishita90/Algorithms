/*
DFS: Iterative method of traversal of binary tree
list nodes_to_visit = {root};
while( nodes_to_visit isn't empty ) {
  currentnode = nodes_to_visit.take_first();
  nodes_to_visit.prepend( currentnode.children );
  //do something
}
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
  vector<int> dfs_traversal(TreeNode* root){
    if (root == NULL)
      return 0
    std::vector<int> res;
    std::stack<TreeNode*> dfs_stack;
    dfs_stack.push(root);
    while(!dfs_stack.empty()){
      TreeNode* curr_node = dfs_stack.top(); dfs_stack.pop();
      res.push_back(curr_node->val);
      if(curr_node->right != NULL) dfs_stack.push(curr_node->right);
      if(curr_node->left != NULL) dfs_stack.push(curr_node->left);
    }
    return res;
  }
}
