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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto root = build_tree(
            inorder.begin(), 
            inorder.end(), 
            postorder.begin(), 
            postorder.end()
        );
        return root;
    }
    
    TreeNode* build_tree(it in_begin, it in_end, it post_begin, it post_end) {
        if(in_begin == in_end){
            return nullptr;
        }
        
        int val = *(post_end - 1);
        
        it in_mid = find(in_begin, in_end, val);
        it post_mid = post_begin + (in_mid - in_begin);
        
        auto left_child = build_tree(
            in_begin,
            in_mid,
            post_begin,
            post_mid
        );
        auto right_child = build_tree(
            in_mid + 1,
            in_end,
            post_mid,
            post_end - 1
        );
        
        auto node = new TreeNode(val);
        node->left = left_child;
        node->right = right_child;

        return node;
    }
};
