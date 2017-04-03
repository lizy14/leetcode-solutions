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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    bool isValidBST(TreeNode* root, TreeNode* lower, TreeNode* upper) {
        if(!root){
            return true;
        }
        if(lower && root->val <= lower->val){
            return false;
        }
        if(upper && root->val >= upper->val){
            return false;
        }
        return 
            isValidBST(root->left, lower, root) && 
            isValidBST(root->right, root, upper);
    }
};
