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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        if(root == NULL) return 0;
        if(low <= root->val && root->val<= high){
            sum = sum + root->val;
        }
     int leftSum =  rangeSumBST(root->left , low , high);
      int rightSum = rangeSumBST(root->right , low , high);
        return sum + leftSum + rightSum;
    }
};