/*
BFS : Iterative method of traversal of binary tree
list nodes_to_visit = {root};
while( nodes_to_visit isn't empty ) {
  currentnode = nodes_to_visit.take_first();
  nodes_to_visit.append( currentnode.children );
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

 class Solution {
public:
    vector<int> bfs_traversal(TreeNode* root) {
      if(root == NULL)
        return {};
        std::queue<TreeNode*> q; std::vector<int> res;
        q.push(root);
        while(!q.empty() ) //&& root != NULL){
              TreeNode *temp = q.front();
              q.pop();
              std::cout<<" "<<temp->val<<std::endl;
              res.push_back(temp->val);
              if(temp->left != NULL) q.push(temp->left);
              if(temp->right != NULL) q.push(temp->right);
        }
        return res;
    }

};
