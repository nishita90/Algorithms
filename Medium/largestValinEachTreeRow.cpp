/*
LeetCode:
You need to find the largest value in each row of a binary tree.
Input:
          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
 public:
     vector<int> largestValues(TreeNode* root) {
         std::queue<TreeNode*> q; std::vector<int> res; int currMax;
         q.push(root);
         //Check if root is null
         int q_length = root == NULL ? 0 : 1;
         std::cout<<q_length<<std::endl;
         while(q_length > 0){
             currMax = INT_MIN;
             for(int i=0; i<q_length;i++){
                 TreeNode *temp = q.front();
                 q.pop();
                 //std::cout<<" "<<temp->val<<std::endl;
                 currMax = std::max(temp->val,currMax);
                 if(temp->left != NULL) q.push(temp->left);
                 if(temp->right != NULL) q.push(temp->right);
             }
             res.push_back(currMax);
             q_length = q.size();
         }
         return res;
     }

 };
