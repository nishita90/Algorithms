/*
Given a binary tree, find the leftmost value in the last row of the tree.
Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

 /* Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 class Solution {
 public:
     int findBottomLeftValue(TreeNode* root) {
         if(root == NULL)
             return 0;
         int leftMostVal = root->val;
         std::queue<TreeNode*> bfs_q;
         bfs_q.push(root);
         while(!bfs_q.empty() && root != NULL){
             TreeNode* temp = bfs_q.front(); bfs_q.pop();
             if(temp->right != NULL) {
                 bfs_q.push(temp->right);
                 if(temp->left == NULL)
                     leftMostVal = (temp->right)->val;
             }
             if(temp->left != NULL) {
                 bfs_q.push(temp->left);
                 leftMostVal = (temp->left)->val;
             }

         }

         return (leftMostVal);
     }
 };
