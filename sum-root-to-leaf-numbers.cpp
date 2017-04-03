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
    typedef pair<int, int> sum_t; // sum, multiplier
public:
    int sumNumbers(TreeNode* root) {
        return helper(root).first;
    }
    
    sum_t helper(TreeNode* root){
        if(root == nullptr){
            return sum_t(0, 0);
        }
        if(root->left == nullptr && root->right == nullptr){
            return sum_t(root->val, 10);
        }
        auto l = helper(root->left);
        auto r = helper(root->right);
        
        int sum = l.first + r.first + root->val * (l.second + r.second);
        int multiplier = 10 * (l.second + r.second);
        return sum_t(sum, multiplier);
    }


};
