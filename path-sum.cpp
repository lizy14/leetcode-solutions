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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr){
            return sum == root->val;
        }
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
