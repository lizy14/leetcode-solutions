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
    int _max;
public:
    int maxDepth(TreeNode* root) {
        _max = 0;
        go(root, 0);
        return _max;
    }
    void go(TreeNode* root, int depth){
        if(root == nullptr){
            _max = max(_max, depth);
            return;
        }
        go(root->left, depth + 1);
        go(root->right, depth + 1);
    }
    
};
