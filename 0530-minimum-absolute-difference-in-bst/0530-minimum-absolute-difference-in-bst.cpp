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
    int ans = INT_MAX;
        int prev = INT_MIN;
    int getMinimumDifference(TreeNode* root) {
        
        if(root == NULL) return ans;
        //call on left
        getMinimumDifference(root->left);
        //process the root
        if(prev!= INT_MIN){
             ans = min(ans,abs(root->val-prev));
        
        }
        if(root!=NULL){
            prev = root->val;
        }
        //call on right
        getMinimumDifference(root->right);
        return ans;
    }
    
};