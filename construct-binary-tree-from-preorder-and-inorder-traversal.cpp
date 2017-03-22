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
    typedef vector<int>::iterator it;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_tree(
            preorder.begin(),
            preorder.end(),
            inorder.begin(),
            inorder.end()
        );
    }
    TreeNode* build_tree(it pre_begin, it pre_end, it in_begin, it in_end){
        if(pre_begin == pre_end){
            return nullptr;
        }
        
        int val = *pre_begin;
        
        it in_mid = find(in_begin, in_end, val);
        it pre_mid = pre_begin + (in_mid - in_begin) + 1;
        
        auto left = build_tree(
            pre_begin + 1,
            pre_mid,
            in_begin,
            in_mid
        );
        auto right = build_tree(
            pre_mid,
            pre_end,
            in_mid + 1,
            in_end
        );
        
        auto root = new TreeNode(val);
        root->left = left;
        root->right = right;
        
        return root;
    }
};
