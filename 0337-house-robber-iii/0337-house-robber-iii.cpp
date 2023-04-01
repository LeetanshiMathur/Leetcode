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
 vector<int>helper (TreeNode* root){
     vector<int> result(2,0) ;
     if(root == NULL) {
     result[0] = 0;
     result[1] = 0;
         return result;
     }
     vector<int> left =  helper(root->left);
     vector<int> right = helper(root->right);
     
     result[0] = root->val + left[1] + right[1] ; //if selected
     result[1] = max(left[0] , left[1]) + max(right[0] , right[1]); //if not selected
     return result;
        
 }
    int rob(TreeNode* root) {

        vector<int>ans = helper(root);
        return max(ans[0] , ans[1]);
    }
};