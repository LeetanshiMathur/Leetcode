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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        TreeNode* node =new TreeNode(root->val); 
        
        if(root == p || root == q)
             return root;
          
            // if(root->left == p && root->right ==q)
            //  node->val = min(root->val , node->val);
            
        
        TreeNode * leftLCA = lowestCommonAncestor(root->left, p , q);
        TreeNode * rightLCA = lowestCommonAncestor(root->right , p ,q);
        if (leftLCA && rightLCA)
        return root;
 
    // Otherwise check if left subtree or right subtree is
    // LCA
    return (leftLCA != NULL) ? leftLCA : rightLCA;
        
    }
};