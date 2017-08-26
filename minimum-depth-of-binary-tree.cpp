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
    int _min;
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        _min = -1;
        getDepth(root, 1);
        return _min;
    }
    
    inline void foundLeaf(int depth){
        if(_min == -1 || depth < _min){
            _min = depth;
        }
    }
    inline bool isLeaf(TreeNode* node){
        return node->left == nullptr && node->right == nullptr;
    }
    void getDepth(TreeNode* root, int depth){
        if(root == nullptr){
            return;
        }
        cout << root->val << ", " << depth << endl;
        if(isLeaf(root)){
            foundLeaf(depth);
            return;
        }
        getDepth(root->left, depth + 1);
        getDepth(root->right, depth + 1);
    }
};
