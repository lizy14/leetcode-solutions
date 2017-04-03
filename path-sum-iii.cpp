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
    int pathSum(TreeNode* root, int sum, bool parent_in_use = false) {
        if(root == nullptr){
            return 0;
        }
        int result = 0;
        if(sum == root->val){
            result += 1;
        }
        result += pathSum(root->left, sum - root->val, true);
        result += pathSum(root->right, sum - root->val, true);
        if(!parent_in_use){
            result += pathSum(root->left, sum);
            result += pathSum(root->right, sum);
        }
        return result;
    }
};
