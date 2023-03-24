/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return {};
   
        queue<TreeNode*>q;
        q.push(root);
        // bool isLeftToRight = true;
       int count=1;
        while (!q.empty()) {
           
       int size = q.size();
      vector<int> currLevel;
      for (int i = 0; i < size; i++) {
        TreeNode*node = q.front();
        q.pop();
        // const int index = isLeftToRight ? i : size - i - 1;
        // currLevel[index] = node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
          currLevel.push_back(node->val);
      }
            if(count % 2 == 0)
            reverse(currLevel.begin() , currLevel.end());
      result.push_back(currLevel);
             count++;
      // isLeftToRight = !isLeftToRight;
    }

    return result;
        }
};